#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

namespace cds_semaphore {
    class Semaphore {
    private:
        std::mutex mt;
        std::condition_variable cv;
        bool is_unlocked;
    public:
        Semaphore();

        void wait();

        void notify();

    };

    Semaphore::Semaphore() : mt{}, cv{}, is_unlocked{true} {}

    void Semaphore::wait() {
        std::unique_lock<std::mutex> lk(mt);
        cv.wait(lk, [this] { return is_unlocked; });
        is_unlocked = false;
        //lk released on destructor
    }

    void Semaphore::notify() {
        is_unlocked = true;
        cv.notify_all();
    }

    void DoWork(cds_semaphore::Semaphore &s, int &i) {
        s.wait();

        int j = i;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        i = j + 1;
        std::cout << i << "\n";

        s.notify();
    }
} // namespace cds_semaphore

int main() {
    const int thread_num = 10000;
    int shared_value = 0;
    cds_semaphore::Semaphore s{};
    std::vector<std::thread> thread_vec{};
    thread_vec.reserve(thread_num);
    for (int i = 0; i < thread_num; i++) {
        thread_vec.emplace_back(cds_semaphore::DoWork, std::ref(s), std::ref(shared_value));
    }
    for (auto &t: thread_vec) {
        t.join();
    }
}