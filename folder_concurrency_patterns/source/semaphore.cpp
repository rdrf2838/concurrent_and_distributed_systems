//
// Created by ivin on 22/12/21.
//
#include "patterns.hpp"

namespace cds::patterns {
    Semaphore::Semaphore(int c) : mt{}, cv{}, count{c} {}

    void Semaphore::wait() {
        std::unique_lock<std::mutex> lk(mt);
        cv.wait(lk, [this] { return count > 0; });
        count -= 1;
        //lk released on destructor
    }

    void Semaphore::notify() {
        std::unique_lock<std::mutex> lk(mt);
        count += 1;
        cv.notify_one();
    }

    ConditionVariable::ConditionVariable() : mt{}, cv{} {}

    void ConditionVariable::wait() {
        std::unique_lock<std::mutex> lk(mt);
        cv.wait(lk);
    }

    void ConditionVariable::notify_all() {
        cv.notify_all();
    }
}
