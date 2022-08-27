/* 79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 
Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 
Follow up: Could you use search pruning to make your solution faster with a larger board?

*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool tf = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                dfs(board, word, i, j, 0, tf);
            }
        }
        return tf;
    }
    
    void dfs(vector<vector<char>>& b, string &w, int m, int n, int index, bool &tf){
        if(m < 0 || n < 0 || m >= b.size() || n >= b[0].size() || tf || b[m][n] == '#')
            return;
        
        if(b[m][n] == w[index]){
            if(index + 1 == w.size()){
                tf = true;
                return;
            }
            
            char temp = b[m][n];
            b[m][n] = '#';
            
            dfs(b, w, m - 1, n, index + 1, tf);
            dfs(b, w, m + 1, n, index + 1, tf);
            dfs(b, w, m, n - 1, index + 1, tf);
            dfs(b, w, m, n + 1, index + 1, tf);
            
            b[m][n] = temp;
        }
    }
};

/*

Time: O( n * 3^l) n is the number of cells and l is the length of the word. It is 3 because we have
3 paths forwards since we cannot move back to the cell we visited.

Space: O(1)

The fastest solution was:

class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, const string& word, int x, int y,int index)
    {
        if(word[index] != board[x][y])
            return false;
        
        board[x][y] = '*';
        
        if(word.size() - 1 == index)
            return true;
        
        static const int dir_x[4] = {0,0,1,-1};
        static const int dir_y[4] = {1,-1,0,0};
        
        for(int i = 0; i < 4; ++i)
        {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if(new_x < 0 || new_x >= board.size() ||
              new_y < 0 || new_y >= board[0].size())
                continue;
            if(dfs(board,word,new_x,new_y, index + 1))
                return true;
        }
        
        board[x][y] = word[index];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        //先遍历全局，遇到首字母就开一个DFS进程去看是否有完全匹配的路径
        
        if(board.size() * board[0].size() < word.size())
            return false;
        
        int frequency[128] = {};
        for(const auto &row : board) 
        {
            for(char chr : row) 
            {
                ++frequency[chr];
            }
        }
        for(char chr : word) 
        {
            if(--frequency[chr] < 0) 
                return false;
        }
        
        int left_pref = word.find_first_not_of(word[0]);
        int right_pref = word.size() - word.find_last_not_of(word.back());
        if(left_pref > right_pref) {
            reverse(word.begin(), word.end());
        }        
        
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j <board[0].size(); ++j)
            {
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};

*/