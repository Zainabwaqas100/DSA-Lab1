#include <iostream>
#include <vector>
using namespace std;

// Function declaration
vector<int> findAllIndices(const vector<int>& arr, int key);

void printResult(const vector<int>& result)
{
    cout << "{ ";

    for (int index : result)
    {
        cout << index << " ";
    }

    cout << "}" << endl;
}

int main()
{
    // Test 1: Multiple occurrences
    vector<int> arr1 = {5, 4, 5, 4, 5, 5};
    vector<int> result1 = findAllIndices(arr1, 5);

    cout << "Test 1: ";
    printResult(result1);

    // Test 2: Key not present
    vector<int> arr2 = {5, 5, 5, 5};
    vector<int> result2 = findAllIndices(arr2, 9);

    cout << "Test 2: ";
    printResult(result2);

    // Test 3: Empty array
    vector<int> arr3;
    vector<int> result3 = findAllIndices(arr3, 5);

    cout << "Test 3: ";
    printResult(result3);

    return 0;
}

