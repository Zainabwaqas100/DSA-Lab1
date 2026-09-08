#include "mode_array.h"
#include <unordered_map>
#include <algorithm>

std::vector<int> findModes(const std::vector<int>& arr) {
    std::vector<int> modes;
    if (arr.empty()) return modes;

    std::unordered_map<int, int> freq;
    for (int v : arr) {
        freq[v]++;
    }

    int maxFreq = 0;
    for (const auto& entry : freq) {
        maxFreq = std::max(maxFreq, entry.second);
    }

    for (const auto& entry : freq) {
        if (entry.second == maxFreq) {
            modes.push_back(entry.first);
        }
    }

    std::sort(modes.begin(), modes.end());
    return modes;
}
