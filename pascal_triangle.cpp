#include "pascal_triangle.h"

std::vector<std::vector<int>> generatePascalsTriangle(int n) {
    std::vector<std::vector<int>> triangle;
    if (n <= 0) return triangle;

    triangle.reserve(n);
    for (int row = 0; row < n; ++row) {
        std::vector<int> current(row + 1, 1);
        for (int k = 1; k < row; ++k) {
            current[k] = triangle[row - 1][k - 1] + triangle[row - 1][k];
        }
        triangle.push_back(current);
    }
    return triangle;
}