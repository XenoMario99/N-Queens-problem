#include "queens.h"

#include <algorithm>
#include <cmath>
#include <iostream>

namespace queens {

using Positions = std::vector<Column>;  // i - row, col[i] - column

namespace {

bool promissing(const Row& row, const Positions& positions) {
    bool isValid{true};
    for (int i = 0; i < row; i++) {
        if (positions[i] == positions[row] || ((row - i) == std::abs((positions[row] - positions[i])))) {
            isValid = false;
            break;
        }
    }

    return isValid;
}

void queen(const Row& row, Positions& positions) {
    if (promissing(row, positions)) {
        if (row == positions.size() - 1) {
            std::cout << std::endl;
            for (const auto& x : positions) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        } else {
            for (int j = 0; j < positions.size(); j++) {
                positions[row + 1] = j;  // next row
                queen(row + 1, positions);
            }
        }
    }
}

}  // namespace

void queens(const int n) {
    for (int j = 0; j < n; j++) {
        Positions positions(n, 0);
        positions[0] = j;
        queen(0, positions);
    }
}

}  // namespace queens