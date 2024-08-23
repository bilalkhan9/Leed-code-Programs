#include <iostream>
#include <string>
#include <limits> 

int myAtoi(const std::string& s) {
    int i = 0;
    int n = s.size();
    int sign = 1;
    long long result = 0; 
    
    
    while (i < n && s[i] == ' ') {
        ++i;
    }
    
    
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        ++i;
    }
    
    
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');
        
    
        if (result > std::numeric_limits<int>::max()) {
            return (sign == 1) ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
        }
        
        ++i;
    }
    
    
    return sign * static_cast<int>(result);
}

int main() {
    std::string input = "42"; 
    int result = myAtoi(input);
    
    std::cout << "Input string: \"" << input << "\"" << std::endl;
    std::cout << "Converted integer: " << result << std::endl;
	system("pause");    
    return 0;
}
