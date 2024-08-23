#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(const string& s) {
    stack<int> stk;
    stk.push(-1); 
    int maxLength = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            stk.push(i); 
        } else { 
            stk.pop(); 
            if (stk.empty()) {
                stk.push(i); 
            } else {
                maxLength = max(maxLength, i - stk.top()); 
            }
        }
    }

    return maxLength;
}

int main() {
    string s1 = "(()";
    string s2 = ")()())";
    string s3 = "";

    cout << "Input: " << s1 << endl;
    cout << "Output: " << longestValidParentheses(s1) << endl; // Output: 2

    cout << "Input: " << s2 << endl;
    cout << "Output: " << longestValidParentheses(s2) << endl; // Output: 4

    cout << "Input: " << s3 << endl;
    cout << "Output: " << longestValidParentheses(s3) << endl; // Output: 0
	system("pause");
    return 0;
}
