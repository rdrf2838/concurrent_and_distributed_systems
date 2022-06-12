#include "occ.h"

namespace cpac = cds::patterns::app::occ;

static void WriterRunner(cpac::Validator &validator) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // for(int i = 0; i < 2; i++) {
    for(int i = 0; i < 5; i++) {
        cpac::Data_t d{};
        std::uniform_int_distribution<> distrib(1, cpac::data_num);
        int num_to_read = distrib(gen);
        std::set<int> idx_to_read;
        for (int i = 0; i < num_to_read; i++) {
            idx_to_read.insert(distrib(gen) - 1);
        }
        num_to_read = idx_to_read.size();
        int read_idxs[num_to_read], read_vals[num_to_read]{}, read_time[num_to_read]{};
        std::copy(idx_to_read.begin(), idx_to_read.end(), read_idxs);

        d.read_len = num_to_read;
        d.read_idxs = read_idxs;
        d.read_time = read_time;
        d.read_vals = read_vals;
        validator.read(&d);

        // d.print_data();

        std::uniform_int_distribution<> distrib2(1, idx_to_read.size());
        int num_to_write = distrib2(gen);
        std::set<int> idx_to_write;
        for (int i = 0; i < num_to_write; i++) {
            idx_to_write.insert(*(std::next(idx_to_read.begin(), distrib2(gen) - 1)));
        }
        num_to_write = idx_to_write.size();
        std::vector<int> vals_to_write;
        for (int i = 0; i < num_to_write; i++) {
            vals_to_write.push_back(distrib(gen));
        }
        int idxs2[num_to_write], vals2[num_to_write];
        std::copy(idx_to_write.begin(), idx_to_write.end(), idxs2);
        std::copy(vals_to_write.begin(), vals_to_write.end(), vals2);

        d.write_len = num_to_write;
        d.write_idxs = idxs2;
        d.write_vals_next = vals2;
        validator.write(&d);
    }
}

int main() {
    cpac::Validator validator{};
    // WriterRunner(validator);
    // validator.process_data();
    // WriterRunner(validator);
    // validator.process_data();
    // validator.print_data();
    std::vector<std::thread> threads;
    threads.emplace_back(cpac::ValidatorRunner, std::ref(validator));
    for (int i = 0; i < 5; i++) {
        threads.emplace_back(WriterRunner, std::ref(validator));
    }
    for (auto &t : threads) {
        t.join();
    }
}