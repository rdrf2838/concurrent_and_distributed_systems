//
// Created by ivin on 22/12/21.
//

#ifndef CONCURRENT_AND_DISTRIBUTED_SYSTEMS_PATTERNS_HPP
#define CONCURRENT_AND_DISTRIBUTED_SYSTEMS_PATTERNS_HPP

#include <condition_variable>
#include <mutex>

namespace cds::patterns {
    class Semaphore {
    private:
        std::mutex mt;
        std::condition_variable cv;
        int count;
    public:
        explicit Semaphore(int);

        void wait();

        void notify();

    };

    class ConditionVariable {
    private:
        std::mutex mt;
        std::condition_variable cv;
    public:
        ConditionVariable();
        void wait();
        void notify_all();
    };
} // namespace cds::patterns

#endif //CONCURRENT_AND_DISTRIBUTED_SYSTEMS_PATTERNS_HPP
