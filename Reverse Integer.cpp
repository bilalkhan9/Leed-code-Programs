#include <iostream>
#include <limits> 

int reverse(int x) {
    int reversed = 0;
    
    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        
        
        if (reversed > std::numeric_limits<int>::max() / 10 || 
            (reversed == std::numeric_limits<int>::max() / 10 && digit > 7)) {
            return 0; 
        }
        if (reversed < std::numeric_limits<int>::min() / 10 || 
            (reversed == std::numeric_limits<int>::min() / 10 && digit < -8)) {
            return 0; 
        }
        
        reversed = reversed * 10 + digit;
    }
    
    return reversed;
}

int main() {
    int x = 123; 
    int result = reverse(x);
    
    std::cout << "Reversed integer: " << result << std::endl;
		  system("pause");
	    return 0;
}
