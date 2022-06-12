#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void f(int &i, const int &n, std::mutex &mutex) {
    std::lock_guard<std::mutex> m(mutex);
    for (int j = 0; j < n; j++) {
        i += 1;
        std::cout << i << "\n";
    }
}

int another_main() {
    int i = 0;
    int n = 100;
    std::mutex my_mutex;
    std::vector<std::thread> thread_list;
    thread_list.reserve(n);
    for (int j = 0; j < n; j++) {
        std::thread t(f, std::ref(i), n, std::ref(my_mutex));
        thread_list.push_back(std::move(t));
    }
    for (auto &t : thread_list) {
        t.join();
    }
    return 0;
}
