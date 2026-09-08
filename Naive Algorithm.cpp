#include "Naive_algorithm.h"

int firstOccurrence(const std::string& text, const std::string& pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    if (m == 0) return 0;      
    if (m > n) return -1;

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            return i;          
        }
    }
    return -1;
}