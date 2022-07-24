/* 36. Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to
the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 
Example 1:

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since
there are two 8's in the top left 3x3 sub-box, it is invalid.
 
Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        map<pair<int, int>, bool> um_row;
        map<pair<int, int>, bool> um_col;
        map<pair<int, int>, bool> um_box;
        int k;
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != '.'){
                    if(um_row[make_pair(i, board[i][j])] != 1){
                        um_row[make_pair(i, board[i][j])] = 1;
                    }else{
                        return false;
                    }
                    
                    if(um_col[make_pair(j, board[i][j])] != 1){
                        um_col[make_pair(j, board[i][j])] = 1;
                    }else{
                        return false;
                    }
                    
                    k = i / 3 * 3 + j / 3;
                    
                    if(um_box[make_pair(k, board[i][j])] != 1){
                        um_box[make_pair(k, board[i][j])] = 1;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

/* Note

I had to look at the discussion to figure out how to check the boxes if the number has appeared. 
Everything is similar except for
    
k = i / 3 * 3 + j / 3;

The solution stores a pair of integers in a map for the rows and columns and box to check if we
have visited the number before.

*/