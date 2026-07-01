#pragma once

#include <optional>

namespace math {

/// Tries to add @p x and @p y, or returns `std::nullopt` if overflow would occur.
auto checked_add(int x, int y) -> std::optional<int>;

} // namespace math
