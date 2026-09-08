#include <iostream>
#include <vector>
#include "mode_array.h"
using namespace std;

void printVec(const vector<int>& v) {
    cout << "{";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "}";
}

bool checkEqual(const vector<int>& got, const vector<int>& expected, const string& name) {
    bool pass = (got == expected);
    cout << name << ": " << (pass ? "PASS" : "FAIL")
         << " (got "; printVec(got); cout << ", expected "; printVec(expected); cout << ")" << endl;
    return pass;
}

int main() {
    // Unique mode
    checkEqual(findModes({1, 2, 2, 3, 2, 4}), {2}, "Unique mode");

    // Multiple modes (tie)
    checkEqual(findModes({1, 1, 2, 2, 3}), {1, 2}, "Multiple modes");

    // Empty array
    checkEqual(findModes({}), {}, "Empty array");

    // All unique (every value is a mode)
    checkEqual(findModes({5, 3, 9}), {3, 5, 9}, "All unique values");

    return 0;
}
