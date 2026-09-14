#include "math.hpp"

#include <limits>
#include <optional>

namespace math {

auto checked_add(const int x, const int y) -> std::optional<int> {
  if (y > 0 && x > std::numeric_limits<int>::max() - y) {
    return std::nullopt; // Positive overflow
  }
  if (y < 0 && x < std::numeric_limits<int>::min() - y) {
    return std::nullopt; // Negative overflow
  }
  return x + y;
}

} // namespace math
