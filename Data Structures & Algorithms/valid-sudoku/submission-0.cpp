#include <map>
#include <set>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<int>> cols;
        map<int, set<int>> rows;
        map<int, set<int>> squares; //key = (r/3 * 3 + col/3)
        for (int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] == '.') {
                    continue;
                }
                if(rows[r].contains(board[r][c])) {
                    return false;
                }
                if(cols[c].contains(board[r][c])) {
                    return false;
                }
                if(squares[(r/3) * 3 + (c/3)].contains(board[r][c])) {
                    return false;
                }
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[(r/3) * 3 + (c/3)].insert(board[r][c]);
            }
        }
        return true;
    }
};