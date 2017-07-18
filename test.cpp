#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "timer.hpp"

TEST_CASE("All methods of the timer has to be run." ) {
  Timer timer;
  timer.call([](){std::cout << "Hello world 0!\n";}, 0, 1);
  timer.call([](){std::cout << "Hello world 1!\n";}, 0, 1);
  for (auto &future : timer.futures){
    future.wait();
  }
  REQUIRE(timer.futures[0].wait_for(std::chrono::seconds(0)) == std::future_status::ready);
  REQUIRE(timer.futures[1].wait_for(std::chrono::seconds(0)) == std::future_status::ready);
}

TEST_CASE("Test timer not run.") {
  Timer timer(false);
  timer.call([](){std::cout << "Hello world 0!\n";}, 0, 1);
  REQUIRE(timer.futures[0].wait_for(std::chrono::seconds(0)) == std::future_status::timeout);
  CHECK(!timer.run);
}

TEST_CASE("Test timer restart.") {
  Timer timer(false);
  timer.call([](){std::cout << "Hello world 0!\n";}, 0, 1);
  timer.run = true;
  timer.futures[0].wait();
  REQUIRE(timer.futures[0].wait_for(std::chrono::seconds(0)) == std::future_status::ready);
  CHECK(timer.run);
}

TEST_CASE("Test clear.") {
  Timer timer;
  timer.call([](){std::cout << "Hello world 0!\n";}, 0, 1);
  timer.futures.clear();

  //REQUIRE(timer.futures[0].wait_for(std::chrono::seconds(0)) == std::future_status::ready);
  CHECK(timer.run);
}