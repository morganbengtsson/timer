#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "timer.hpp"

TEST_CASE("Function has run." ) {
  Timer timer([](){std::cout << "Hello world 0!\n";}, 0, 1);
  timer.future.wait();
  REQUIRE(timer.future.wait_for(std::chrono::seconds(0)) == std::future_status::ready);
}


TEST_CASE("Test stop." ) {
  Timer timer([](){std::cout << "Hello world 0!\n";}, 0, 1000);
  timer.stop();
  timer.future.wait();
  REQUIRE(timer.future.wait_for(std::chrono::seconds(0)) == std::future_status::ready);
}

