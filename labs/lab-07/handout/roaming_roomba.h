#pragma once
#include <cstdint>
#include <vector>

using u32 = uint32_t;

enum class Cell {
    Home, Dirty, Clean, Wall
};

[[nodiscard]] u32 roaming_roomba(const std::vector<std::vector<Cell>>& grid);