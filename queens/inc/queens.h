#pragma once

#include <stdint.h>

#include <vector>

namespace queens {

typedef int16_t Row;
typedef int16_t Column;

void start(const int n);

// struct Position {
//     Row row;
//     Column column;

//     Position() : row(0), column(0) {}
//     Position(const Row& row, const Column& column) : row(row), column(column) {}
//     ~Position() {}
// };

// using Positions = std::vector<Position>;

// Positions getPositions(const int16_t n);  // n - number of queens to be set up

}  // namespace queens
