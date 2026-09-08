#include "strassen.h"
#include <algorithm>
#include <cmath>

Matrix naiveMultiply(const Matrix& A, const Matrix& B) {
    int n = static_cast<int>(A.size());
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            int a = A[i][k];
            if (a == 0) continue;
            for (int j = 0; j < n; ++j) {
                C[i][j] += a * B[k][j];
            }
        }
    }
    return C;
}

static Matrix addMatrix(const Matrix& A, const Matrix& B) {
    int n = static_cast<int>(A.size());
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

static Matrix subMatrix(const Matrix& A, const Matrix& B) {
    int n = static_cast<int>(A.size());
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}


static void splitMatrix(const Matrix& M, Matrix& A11, Matrix& A12, Matrix& A21, Matrix& A22) {
    int half = static_cast<int>(M.size()) / 2;
    A11.assign(half, std::vector<int>(half));
    A12.assign(half, std::vector<int>(half));
    A21.assign(half, std::vector<int>(half));
    A22.assign(half, std::vector<int>(half));
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = M[i][j];
            A12[i][j] = M[i][j + half];
            A21[i][j] = M[i + half][j];
            A22[i][j] = M[i + half][j + half];
        }
    }
}

static Matrix joinMatrix(const Matrix& C11, const Matrix& C12, const Matrix& C21, const Matrix& C22) {
    int half = static_cast<int>(C11.size());
    int n = half * 2;
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
    return C;
}


static Matrix strassenRecursive(const Matrix& A, const Matrix& B) {
    int n = static_cast<int>(A.size());


    if (n <= 2) {
        return naiveMultiply(A, B);
    }

    Matrix A11, A12, A21, A22, B11, B12, B21, B22;
    splitMatrix(A, A11, A12, A21, A22);
    splitMatrix(B, B11, B12, B21, B22);

    Matrix M1 = strassenRecursive(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix M2 = strassenRecursive(addMatrix(A21, A22), B11);
    Matrix M3 = strassenRecursive(A11, subMatrix(B12, B22));
    Matrix M4 = strassenRecursive(A22, subMatrix(B21, B11));
    Matrix M5 = strassenRecursive(addMatrix(A11, A12), B22);
    Matrix M6 = strassenRecursive(subMatrix(A21, A11), addMatrix(B11, B12));
    Matrix M7 = strassenRecursive(subMatrix(A12, A22), addMatrix(B21, B22));

    Matrix C11 = addMatrix(subMatrix(addMatrix(M1, M4), M5), M7);
    Matrix C12 = addMatrix(M3, M5);
    Matrix C21 = addMatrix(M2, M4);
    Matrix C22 = addMatrix(subMatrix(addMatrix(M1, M3), M2), M6);

    return joinMatrix(C11, C12, C21, C22);
}

Matrix strassenMultiply(const Matrix& A, const Matrix& B) {
    int n = static_cast<int>(A.size());


    int size = 1;
    while (size < n) size *= 2;

    Matrix Apad(size, std::vector<int>(size, 0));
    Matrix Bpad(size, std::vector<int>(size, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Apad[i][j] = A[i][j];
            Bpad[i][j] = B[i][j];
        }
    }

    Matrix Cpad = strassenRecursive(Apad, Bpad);

    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = Cpad[i][j];

    return C;
}
