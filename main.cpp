#include <iostream>

#include "timer.hpp"

int main() {
  Timer t;
  t.call([](){std::cout << "Hello world!\n";}, 2, 3);
  t.call([](){std::cout << "Hello other world!\n";}, 1, 1);
  return 0;
}