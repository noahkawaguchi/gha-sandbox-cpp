#include <limits>

#include <catch2/catch_test_macros.hpp>

#include "math.hpp"

using namespace math;

TEST_CASE("checked_add performs basic arithmetic", "[math]") {
  CHECK(checked_add(2, 2) == 4);
  CHECK(checked_add(2345, 10'000) == 12'345);
  CHECK(checked_add(-333, 30) == -303);
  CHECK(checked_add(-2, -25) == -27);
}

TEST_CASE("checked_add detects positive overflow", "[math]") {
  CHECK_FALSE(checked_add(std::numeric_limits<int>::max(), 1).has_value());
  CHECK_FALSE(
    checked_add(std::numeric_limits<int>::max(), std::numeric_limits<int>::max()).has_value());
}

TEST_CASE("checked_add detects negative overflow", "[math]") {
  CHECK_FALSE(checked_add(std::numeric_limits<int>::min(), -1).has_value());
  CHECK_FALSE(
    checked_add(std::numeric_limits<int>::min(), std::numeric_limits<int>::min()).has_value());
}
