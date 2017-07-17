#ifndef TIMER_TIMER_HPP
#define TIMER_TIMER_HPP

#include <chrono>
#include <functional>
#include <future>
#include <vector>

class Timer {
public:
  void call(const std::function<void()> & func, const int delay, const int runs = 1);
private:
  std::vector<std::future<void>> futures_;
};

#endif //TIMER_TIMER_HPP
