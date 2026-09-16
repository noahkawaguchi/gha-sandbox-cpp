#pragma once

#include <optional>

namespace math {

/// Attempts to add @p x and @p y, returning `std::nullopt` if overflow would occur.
auto checked_add(int x, int y) -> std::optional<int>;

} // namespace math
