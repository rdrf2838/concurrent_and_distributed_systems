#include <iostream>
#include <thread>
#include <vector>
#include "patterns.hpp"

static void DoWork(cds::patterns::Semaphore &s, int &i, int idx) {
    s.wait();

    int j = i;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    i = j + 1;
    std::cout << "thread " << idx << " : " << i << "\n";

    s.notify();
}

int main() {
    const int thread_num = 100;
    const int sem_num = 1;
    int shared_value = 0;
    cds::patterns::Semaphore s{sem_num};
    std::vector<std::thread> thread_vec{};
    thread_vec.reserve(thread_num);
    for (int i = 0; i < thread_num; i++) {
        thread_vec.emplace_back(DoWork, std::ref(s), std::ref(shared_value), i);
    }
    for (auto &t: thread_vec) {
        t.join();
    }
}