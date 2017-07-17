#ifndef TIMER_TIMER_HPP
#define TIMER_TIMER_HPP

#include <chrono>
#include <functional>
#include <future>
#include <vector>

class Timer {
public:
  Timer();
  void call(const std::function<void()> & func, const int delay, const int runs = 1);
  std::atomic_bool run;
private:
  std::vector<std::future<void>> futures_;
};

#endif //TIMER_TIMER_HPP
