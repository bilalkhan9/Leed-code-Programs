#include <iostream>
#include <limits>
using namespace std;

int divide(int dividend, int divisor) {
    
    if (divisor == 0) return numeric_limits<int>::max(); // division by zero
    if (dividend == 0) return 0;
    if (dividend == numeric_limits<int>::min() && divisor == -1) return numeric_limits<int>::max();
    
    
    bool negative = (dividend < 0) ^ (divisor < 0);
    
    
    long long dividend_ll = abs((long long)dividend);
    long long divisor_ll = abs((long long)divisor);
    
    long long quotient = 0;
    long long temp = 1;
    long long sum = divisor_ll;
    
    
    while (sum <= dividend_ll) {
        sum <<= 1;
        temp <<= 1;
    }
    
    
    while (temp > 0) {
        if (dividend_ll >= sum) {
            dividend_ll -= sum;
            quotient += temp;
        }
        sum >>= 1;
        temp >>= 1;
    }
    
    
    return negative ? -quotient : quotient;
}

int main() {
    int dividend1 = 10, divisor1 = 3;
    cout << "Output: " << divide(dividend1, divisor1) << endl; // Output: 3
    
    int dividend2 = 7, divisor2 = -3;
    cout << "Output: " << divide(dividend2, divisor2) << endl; // Output: -2
	system("pause");    
    return 0;
}
