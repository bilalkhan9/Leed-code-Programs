#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        bool rowCheck[9][9] = {false}; // For each row, digits 1-9
        bool colCheck[9][9] = {false}; // For each column, digits 1-9
        bool boxCheck[9][9] = {false}; // For each 3x3 box, digits 1-9

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch != '.') {
                    int num = ch - '1'; // Convert char to 0-based index
                    
                    // Calculate the index of the 3x3 box
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    
                    if (rowCheck[i][num] || colCheck[j][num] || boxCheck[boxIndex][num]) {
                        return false; // Found a duplicate
                    }
                    
                    rowCheck[i][num] = true;
                    colCheck[j][num] = true;
                    boxCheck[boxIndex][num] = true;
                }
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    vector<vector<char>> board(9, vector<char>(9));
    
    cout << "Enter the Sudoku board (use '.' for empty cells, enter 9 lines each with 9 characters):" << endl;
    
    // Input handling
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            if (board[i][j] != '.' && (board[i][j] < '1' || board[i][j] > '9')) {
                cout << "Invalid character entered. Please use digits '1'-'9' or '.' for empty cells." << endl;
                return 1; // Exit with error code
            }
        }
    }
    
    // Display the input board
    cout << "Input board:" << endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }

    bool isValid = sol.isValidSudoku(board);
    
    cout << "The board is " << (isValid ? "valid" : "invalid") << "." << endl;
    
    return 0;
}
