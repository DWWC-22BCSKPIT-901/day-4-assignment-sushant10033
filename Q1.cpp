1. Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1:
Input: s = "leetcode"
Output: 0
#include <iostream>
#include <unordered_map>
#include <string>

int firstUniqChar(const std::string& s) {
    // Create a hashmap to store character counts
    std::unordered_map<char, int> charCount;
    
    // Count the frequency of each character
    for (char c : s) {
        charCount[c]++;
    }

    // Find the first non-repeating character
    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }

    return -1; // If no non-repeating character exists
}

int main() {
    std::string s = "leetcode";
    int index = firstUniqChar(s);
    std::cout << "Output: " << index << std::endl;
    return 0;
}
