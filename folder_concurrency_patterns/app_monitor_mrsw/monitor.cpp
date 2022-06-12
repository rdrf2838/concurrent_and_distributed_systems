//#include <unistd.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <ctime>

void f(
        int *arr,
        int &idx,
        int thread_num,
        bool &can_continue,
        const int &arr_len,
        std::mutex &mutex,
        std::condition_variable &cv
) {
    while (true) {
        if (idx >= arr_len) {
            break;
        }

        std::unique_lock<std::mutex> lk(mutex);
        cv.wait(lk, [&can_continue, &thread_num] {
            std::cout << "thread " << thread_num << " waiting\n";
            return can_continue;
        });
        can_continue = false;

        arr[idx] = idx;
        idx++;
        for (int i = 0; i < arr_len; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";

        can_continue = true;
        lk.unlock();
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    const int arr_len = 100;
    const int threads_num = arr_len / 10;
    int arr[arr_len]{};
    int idx = 0;
    bool can_continue = true;
    std::vector<std::thread> thread_list;
    std::mutex my_mutex;
    std::condition_variable cv;
    time_t low = std::clock();
    thread_list.reserve(threads_num);
    for (int i = 0; i < threads_num; i++) {
        thread_list.emplace_back(
                f,
                arr,
                std::ref(idx),
                i,
                std::ref(can_continue),
                arr_len,
                std::ref(my_mutex),
                std::ref(cv)
        );
    }
    cv.notify_one();

    for (auto &t: thread_list) {
        t.join();
    }
    time_t high = std::clock();
    std::cout << "time taken: " << high - low << "\n";
}