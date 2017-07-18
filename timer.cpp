#include "timer.hpp"

Timer::Timer(const bool run) :run(run) {
}

void Timer::call(const std::function<void()> &func, const int delay, const int runs) {
  futures.push_back(std::async(std::launch::async, [&](const int delay, const int runs) {
    for(int i = 0; i < runs; i++) {
      if (run) {
        std::this_thread::sleep_for(std::chrono::seconds(delay));
        func();
      }
    }
  }, delay, runs));
}

