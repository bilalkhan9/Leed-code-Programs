#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


map<char, string> digitToLetters;


void initializeDigitToLetters() {
    digitToLetters['2'] = "abc";
    digitToLetters['3'] = "def";
    digitToLetters['4'] = "ghi";
    digitToLetters['5'] = "jkl";
    digitToLetters['6'] = "mno";
    digitToLetters['7'] = "pqrs";
    digitToLetters['8'] = "tuv";
    digitToLetters['9'] = "wxyz";
}


void backtrack(const string& digits, int index, string& current, vector<string>& result) {
    
    if (index == digits.size()) {
        result.push_back(current);
        return;
    }
    
    
    string letters = digitToLetters[digits[index]];
    
    
    for (size_t i = 0; i < letters.size(); ++i) {
        current += letters[i];  
        backtrack(digits, index + 1, current, result); 
        
        
        current = current.substr(0, current.size() - 1);
    }
}


vector<string> letterCombinations(const string& digits) {
    vector<string> result;
    if (digits.empty()) return result;  
    
 
    initializeDigitToLetters();
    
    string current;
    backtrack(digits, 0, current, result);
    
    return result;
}

int main() {
    // Test cases
    vector<string> result1 = letterCombinations("23");
    cout << "Combinations for '23': ";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << result1[i] << " ";
    }
    cout << endl;

    vector<string> result2 = letterCombinations("");
    cout << "Combinations for '': ";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << result2[i] << " ";
    }
    cout << endl;

    vector<string> result3 = letterCombinations("2");
    cout << "Combinations for '2': ";
    for (size_t i = 0; i < result3.size(); ++i) {
        cout << result3[i] << " ";
    }
    cout << endl;
	system("pause");
    return 0;
}
