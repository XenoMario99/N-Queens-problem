#include "queens.h"

#include <cmath>
#include <iostream>

namespace queens {

namespace {

bool diagonalCheck(const Position& position, const Positions& positions) {
    for (const auto& pos : positions) {
        if (std::abs(position.row - pos.row) == std::abs(position.column - pos.column)) {  // Positions are on the same diagonal
            return false;
        }
    }

    return true;
}

bool promissing(const Position& position, int8_t& bitmask, const Positions& positions) {
    return bitmask & (1 << position.column) && diagonalCheck(position, positions);
}

}  // namespace

Positions getPositions(const int16_t n) {
    Positions positions;
    positions.reserve(n);
    int8_t bitmask{0};

    for (Row i = 0; i < n; i++) {
        for (Column j = 0; j < n; j++) {
            if (promissing(Position(i, j), bitmask, positions)) {
                positions.push_back(Position(i, j));
            } else {
            }
        }
    }

    return positions;
}

}  // namespace queens