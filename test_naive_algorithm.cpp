#include <iostream>
#include <string>
#include "Naive_algorithm.h"
using namespace std;

void check(const string& name, int got, int expected) {
    cout << name << ": " << (got == expected ? "PASS" : "FAIL")
         << " (got " << got << ", expected " << expected << ")" << endl;
}

int main() {
    string text = "abcdefghijklmnopqrstuvwxyz";

    // Pattern at the beginning
    check("Pattern at beginning", firstOccurrence(text, "abc"), 0);

    // Pattern at the end
    check("Pattern at end", firstOccurrence(text, "xyz"), 8);

    // Pattern not present
    check("Pattern not present", firstOccurrence(text, "qqq"), -1);

    // Empty pattern
    check("Empty pattern", firstOccurrence(text, ""), 0);

    // Extra: pattern longer than text
    check("Pattern longer than text", firstOccurrence("ab", "abcdefghijklmnopqrstuvwxyzzz"), -1);

    // Extra: pattern in the middle
    check("Pattern in middle", firstOccurrence(text, "mno"), 2);

    return 0;
}