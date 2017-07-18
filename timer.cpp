#include "timer.hpp"
#include <iostream>
Timer::Timer(const std::function<void()> &func,
             const int delay,
             const int runs) : run(true),
                               future(std::async(std::launch::async, [&](const int delay, const int runs) {}, delay, runs)){
  for (int i = 0; i < runs; i++) {
    if (run) {
      std::this_thread::sleep_for(std::chrono::seconds(delay));
      func();
    }
  }
}

void Timer::stop() {
  run = false;
}
