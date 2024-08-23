#include <iostream>
#include <vector>
#include <string>

bool isMatch(const std::string& s, const std::string& p) {
    int m = s.size();
    int n = p.size();
    
    
    std::vector<bool> dp((m + 1) * (n + 1), false);
    dp[0] = true; 
    
    
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[j] = dp[j - 2];
        }
    }

    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            int currentIndex = i * (n + 1) + j;
            int leftIndex = i * (n + 1) + (j - 1);
            int topIndex = (i - 1) * (n + 1) + j;
            int topLeftIndex = (i - 1) * (n + 1) + (j - 1);
            
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[currentIndex] = dp[topLeftIndex];
            } else if (p[j - 1] == '*') {
                
                dp[currentIndex] = dp[leftIndex];
                
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[currentIndex] = dp[currentIndex] || dp[topIndex];
                }
            }
        }
    }

    return dp[m * (n + 1) + n];
}

int main() {
    std::string s = "aa"; 
    std::string p = "a*"; 

    bool result = isMatch(s, p);

    std::cout << "Input string: \"" << s << "\"" << std::endl;
    std::cout << "Pattern: \"" << p << "\"" << std::endl;
    std::cout << "Match result: " << (result ? "true" : "false") << std::endl;
	system("pause");
    return 0;
}
