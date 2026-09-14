#include "math.hpp"

#include <limits>
#include <optional>

namespace math {

auto checked_add(const int x, const int y) -> std::optional<int> {
  return (y > 0 && x > std::numeric_limits<int>::max() - y) // Positive overflow
      || (y < 0 && x < std::numeric_limits<int>::min() - y) // Negative overflow
    ? std::nullopt
    : std::optional{x + y};
}

} // namespace math
