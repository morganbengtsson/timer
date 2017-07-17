#include <iostream>

#include "timer.hpp"

int main() {
  Timer t;
  t.call([](){std::cout << "Hello world!\n";}, 10, 3);
  t.call([](){std::cout << "Hello other world!\n";}, 1, 1);
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << "Hello from main.\n";
  t.run = false;
  return 0;
}