#include <iostream>
#include <vector>
#include "pascal_triangle.h"
using namespace std;

void printTriangle(const vector<vector<int>>& t) {
    for (const auto& row : t) {
        cout << "  {";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i + 1 < row.size()) cout << ", ";
        }
        cout << "}" << endl;
    }
}

int main() {
    // n = 0
    auto t0 = generatePascalsTriangle(0);
    cout << "n = 0: " << (t0.empty() ? "PASS" : "FAIL") << " (rows = " << t0.size() << ")" << endl;

    // n = 1
    auto t1 = generatePascalsTriangle(1);
    bool pass1 = (t1.size() == 1 && t1[0] == vector<int>{1});
    cout << "n = 1: " << (pass1 ? "PASS" : "FAIL") << endl;

    // n = 5, verify row 5 (5th row, index 4) == {1,4,6,4,1}
    auto t5 = generatePascalsTriangle(5);
    cout << "n = 5 triangle:" << endl;
    printTriangle(t5);
    bool pass5 = (t5.size() == 5 && t5[4] == vector<int>{1, 4, 6, 4, 1});
    cout << "Row 5 == {1,4,6,4,1}: " << (pass5 ? "PASS" : "FAIL") << endl;

    return 0;
}
