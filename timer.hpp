#ifndef TIMER_TIMER_HPP
#define TIMER_TIMER_HPP

#include <chrono>
#include <functional>
#include <future>
#include <vector>

class Timer {
public:
  Timer(const bool run = true);
  void call(const std::function<void()> & func, const int delay, const int runs = 1);
  std::atomic_bool run;
  std::vector<std::future<void>> futures;
private:

};

#endif //TIMER_TIMER_HPP
