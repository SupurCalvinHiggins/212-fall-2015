#include "roaming_roomba.h"


u32 roaming_roomba(const std::vector<std::vector<Cell>>& grid) {
    // TODO: Return the minimum battery size required to clean all dirty floors with a Roomba, and return to the home base.
    //
    // Moving into a clean floor costs one unit of energy.
    // Moving into a dirty floor costs three units of energy, and transforms it into a clean floor.
    // Moving into the home base completely recharges the battery.
    //
    // Assume the following:
    // 1. It is impossible for the Roomba to leave the grid (i.e. the grid is surrounded by walls).
    // 2. There is only one home base.
    // 3. The Roomba starts at the home base.
}