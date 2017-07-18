#include <iostream>
#include "timer.hpp"

int main() {
  Timer timer([](){std::cout << "Hello from timer!\n";}, 2, 3);
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << "Hello from main.\n";
  return 0;
}