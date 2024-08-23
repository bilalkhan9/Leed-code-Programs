#include <iostream>
#include <string>

std::string expandAroundCenter(const std::string& s, int left, int right) {
    
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    
    return s.substr(left + 1, right - left - 1);
}

std::string longestPalindrome(const std::string& s) {
    if (s.empty()) {
        return "";
    }

    std::string longest;
    for (int i = 0; i < s.size(); ++i) {
        
        std::string oddPal = expandAroundCenter(s, i, i);
        if (oddPal.size() > longest.size()) {
            longest = oddPal;
        }
        
        
        std::string evenPal = expandAroundCenter(s, i, i + 1);
        if (evenPal.size() > longest.size()) {
            longest = evenPal;
        }
    }
    
    return longest;
}

int main() {
    std::string s = "babad";
    std::string result = longestPalindrome(s);
    
    std::cout << "Longest palindromic substring: " << result << std::endl;
	system("pause");    
    return 0;
}
