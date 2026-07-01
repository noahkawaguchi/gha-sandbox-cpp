#include <cstdio>
#include <cstdlib>
#include <exception>
#include <limits>
#include <optional>
#include <print>
#include <string>
#include <tuple>

#include <zlib.h>

#include "math.hpp"

namespace {

void print_sum(const int x, const int y) {
  std::println(
    "{} + {} = {}", x, y,
    math::checked_add(x, y).transform([](const int x) -> std::string {
    return std::to_string(x);
  }).value_or("nullopt"));
}

void real_main() {
  std::println("zlib version: {}", zlibVersion());

  print_sum(2, 3);
  print_sum(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
}

} // namespace

/// Wraps `real_main` to avoid exception escape.
auto main() -> int {
  try {
    real_main();
  } catch (const std::exception &e) {
    std::ignore = std::fputs("fatal: ", stderr);
    std::ignore = std::fputs(e.what(), stderr);
    std::ignore = std::fputs("\n", stderr);
    return EXIT_FAILURE;
  } catch (...) {
    std::ignore = std::fputs("fatal: unknown exception\n", stderr);
    return EXIT_FAILURE;
  }
}
