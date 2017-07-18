#ifndef TIMER_TIMER_HPP
#define TIMER_TIMER_HPP

#include <chrono>
#include <functional>
#include <future>
#include <vector>

class Timer {
public:
  Timer(const std::function<void()> & func, const int delay, const int runs = 1);
  void stop();
  std::atomic_bool run;
  std::future<void> future;
};

#endif //TIMER_TIMER_HPP
