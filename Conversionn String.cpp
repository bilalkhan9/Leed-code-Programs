#include <iostream>
#include <vector>
#include <string>


std::string convert(const std::string& s, int numRows) {

    if (numRows == 1 || numRows >= s.size()) {
        return s;
    }

    std::vector<std::string> rows(std::min(numRows, static_cast<int>(s.size())));
    int currentRow = 0; 
    bool goingDown = false; 

    
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        rows[currentRow] += c;

    
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }
    
        currentRow += goingDown ? 1 : -1;
    }

    
    std::string result;
    for (int i = 0; i < rows.size(); ++i) {
        result += rows[i];
    }

    return result;
}

int main() {
    
    std::string s = "PAYPALISHIRING";
    int numRows = 3;

    
    std::string converted = convert(s, numRows);
    
    
    std::cout << "Converted string: " << converted << std::endl;
	system("pause");
    return 0;
}
