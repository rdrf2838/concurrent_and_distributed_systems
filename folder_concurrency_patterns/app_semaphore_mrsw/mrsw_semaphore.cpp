#include <iostream>
#include <thread>
#include <vector>
#include "patterns.hpp"

namespace cp = cds::patterns;

namespace cds::patterns::app::mrsw {
    class MRSWSemaphore {
    private:
        cp::Semaphore sem_write, sem_cout;
        int data;
    public:
        MRSWSemaphore();
        void read(int);
        void increment(int);
    };

    MRSWSemaphore::MRSWSemaphore(): sem_write{1}, sem_cout{1}, data{0} {}

    void MRSWSemaphore::read(int idx) {
        sem_write.wait();
        sem_write.notify();

        sem_cout.wait();
        std::this_thread::sleep_for(std::chrono::milliseconds (300));
        std::cout << "thread " << idx << ": " << data << "\n";
        sem_cout.notify();
    }

    void MRSWSemaphore::increment(int idx) {
        sem_write.wait();
        sem_cout.wait();
        int d2 = data;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        data = d2 + 1;
        std::cout << "thread " << idx << ": " << data << "\n";
        sem_cout.notify();
        sem_write.notify();
    }
}

namespace cpam = cp::app::mrsw;

static void AlwaysWrite(cpam::MRSWSemaphore &mrsw, int idx) {
    for (int i = 0; i < 100; i++) {
        mrsw.increment(idx);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

static void AlwaysRead(cpam::MRSWSemaphore &mrsw, int idx) {
    for (int i = 0; i < 100; i++) {
        mrsw.read(idx);
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
}

int main() {
    const int num_readers = 5, num_writers = 1;
    cpam::MRSWSemaphore mrsw{};
    std::vector<std::thread> thread_vec{};
    thread_vec.reserve(num_readers + num_writers);
    for (int i = 0; i < num_writers; i++) {
        thread_vec.emplace_back(AlwaysWrite, std::ref(mrsw), i);
    }
    for (int i = num_writers; i < num_writers + num_readers; i++) {
        thread_vec.emplace_back(AlwaysRead, std::ref(mrsw), i);
    }

    for (auto &t: thread_vec) {
        t.join();
    }
}