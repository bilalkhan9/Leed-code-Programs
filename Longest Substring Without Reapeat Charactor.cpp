#include <iostream>
#include <set> // Include this for std::set
#include <string>

// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(const std::string& s) {
    std::set<char> seen; // Set to track characters in the current window
    int left = 0; // Left boundary of the sliding window
    int maxLength = 0; // Maximum length of substring found
    
    for (int right = 0; right < s.size(); ++right) {
        // If character is already in the set, remove characters from the left
        while (seen.find(s[right]) != seen.end()) {
            seen.erase(s[left]);
            ++left;
        }
        
        // Add the new character to the set and update the maximum length
        seen.insert(s[right]);
        maxLength = std::max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

int main() {
    std::string s = "abcabcbb";
    std::cout << "Input string: " << s << std::endl;
    std::cout << "Length of the longest substring without repeating characters: " 
              << lengthOfLongestSubstring(s) << std::endl;
              system("pause");
    return 0;
}
