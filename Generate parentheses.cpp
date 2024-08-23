#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParenthesis(int n, int open, int close, string current, vector<string>& result) {
    if (current.size() == 2 * n) {
        result.push_back(current);
        return;
    }
    if (open < n) {
        generateParenthesis(n, open + 1, close, current + "(", result);
    }
    if (close < open) {
        generateParenthesis(n, open, close + 1, current + ")", result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesis(n, 0, 0, "", result);
    return result;
}

int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
