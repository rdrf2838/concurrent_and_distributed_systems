#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstddef>
#include <cstdlib>

int main(int argc, char *argv[])
{
    namespace bip = boost::interprocess;

    //Define file names
    const char *FileName  = "file.bin";
    const std::size_t FileSize = 10000;

    if(argc == 1){ //Parent process executes this
        {  //Create a file
            bip::file_mapping::remove(FileName);
            std::filebuf fbuf;
            fbuf.open(FileName, std::ios_base::in | std::ios_base::out
                                | std::ios_base::trunc | std::ios_base::binary);
            //Set the size
            fbuf.pubseekoff(FileSize-1, std::ios_base::beg);
            fbuf.sputc(0);
        }

        //Remove on exit
        struct file_remove
        {
            explicit file_remove(const char *FileName)
                    : FileName_(FileName) {}
            ~file_remove(){ bip::file_mapping::remove(FileName_); }
            const char *FileName_;
        } remover(FileName);

        //Create a file mapping
        bip::file_mapping m_file(FileName, bip::read_write);

        //Map the whole file with read-write permissions in this process
        bip::mapped_region region(m_file, bip::read_write);

        //Get the address of the mapped region
        void * addr       = region.get_address();
        std::size_t size  = region.get_size();

        //Write all the memory to 1
        std::memset(addr, 1, size);

        //Launch child process
        std::string s(argv[0]); s += " child ";
        if(0 != std::system(s.c_str()))
            return 1;
    }
    else{  //Child process executes this
        {  //Open the file mapping and map it as read-only
            bip::file_mapping m_file(FileName, bip::read_only);

            bip::mapped_region region(m_file, bip::read_only);

            //Get the address of the mapped region
            void * addr       = region.get_address();
            std::size_t size  = region.get_size();

            //Check that memory was initialized to 1
            const char *mem = static_cast<char*>(addr);
            for(std::size_t i = 0; i < size; ++i)
                if(*mem++ != 1)
                    return 1;   //Error checking memory
        }
        {  //Now test it reading the file
            std::filebuf fbuf;
            fbuf.open(FileName, std::ios_base::in | std::ios_base::binary);

            //Read it to memory
            std::vector<char> vect(FileSize, 0);
            fbuf.sgetn(&vect[0], std::streamsize(vect.size()));

            //Check that memory was initialized to 1
            const char *mem = static_cast<char*>(&vect[0]);
            for(std::size_t i = 0; i < FileSize; ++i)
                if(*mem++ != 1)
                    return 1;   //Error checking memory
        }
    }

    return 0;
}
