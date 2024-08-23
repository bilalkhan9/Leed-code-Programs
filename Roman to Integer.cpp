#include <iostream>
#include <string>


int getValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0; 
    }
}


int romanToInt(const std::string& s) {
    int total = 0;
    int prevValue = 0;

    
    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        int currentValue = getValue(c);
        if (currentValue > prevValue) {
       
            total += currentValue - 2 * prevValue;
        } else {
      
            total += currentValue;
        }
      
        prevValue = currentValue;
    }

    return total;
}

int main() {
    std::string s1 = "III";
    std::string s2 = "LVIII"; 

    std::cout << "Input: " << s1 << " Output: " << romanToInt(s1) << std::endl;
    std::cout << "Input: " << s2 << " Output: " << romanToInt(s2) << std::endl;
	system("pause");
    return 0;
}
