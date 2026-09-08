#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "strassen.h"
using namespace std;

void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        cout << "  {";
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j];
            if (j + 1 < row.size()) cout << ", ";
        }
        cout << "}" << endl;
    }
}

bool matricesEqual(const Matrix& A, const Matrix& B) {
    return A == B;
}

Matrix randomMatrix(int n, int maxVal = 10) {
    Matrix M(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            M[i][j] = rand() % maxVal;
    return M;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Case 1: 2x2 matrix multiplication
    Matrix A2 = {{1, 2}, {3, 4}};
    Matrix B2 = {{5, 6}, {7, 8}};
    Matrix naive2 = naiveMultiply(A2, B2);
    Matrix strassen2 = strassenMultiply(A2, B2);
    cout << "2x2 test: " << (matricesEqual(naive2, strassen2) ? "PASS" : "FAIL") << endl;
    cout << "  Naive result:" << endl; printMatrix(naive2);
    cout << "  Strassen result:" << endl; printMatrix(strassen2);

    // Case 2: 4x4 matrix multiplication
    Matrix A4 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Matrix B4 = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
    Matrix naive4 = naiveMultiply(A4, B4);
    Matrix strassen4 = strassenMultiply(A4, B4);
    cout << "4x4 test: " << (matricesEqual(naive4, strassen4) ? "PASS" : "FAIL") << endl;

    // Case 3: random values compared with naive (several sizes, including non-power-of-2)
    bool allRandomPass = true;
    for (int size : {3, 5, 8, 6}) {
        Matrix Ar = randomMatrix(size);
        Matrix Br = randomMatrix(size);
        Matrix naiveR = naiveMultiply(Ar, Br);
        Matrix strassenR = strassenMultiply(Ar, Br);
        bool pass = matricesEqual(naiveR, strassenR);
        allRandomPass = allRandomPass && pass;
        cout << "Random " << size << "x" << size << " test: " << (pass ? "PASS" : "FAIL") << endl;
    }
    cout << "All random tests: " << (allRandomPass ? "PASS" : "FAIL") << endl;

    return 0;
}
