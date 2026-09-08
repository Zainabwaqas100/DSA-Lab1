#ifndef STRASSEN_H
#define STRASSEN_H

#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix naiveMultiply(const Matrix& A, const Matrix& B);

Matrix strassenMultiply(const Matrix& A, const Matrix& B);

#endif
