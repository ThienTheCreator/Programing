/* 417. Pacific Atlantic Water Flow

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The
Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's
right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix
heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north,
south, east, and west if the neighboring cell's height is less than or equal to the current cell's
height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can
flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic
oceans.

Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans. 

Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105

*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for(int i = 0; i < m; i++){
            dfs(heights, pacific, i, 0, m, n);
            dfs(heights, atlantic, i, n - 1, m, n);
        }
        
        for(int j = 0; j < n; j++){
            dfs(heights, pacific, 0, j, m, n);
            dfs(heights, atlantic, m - 1, j, m, n);
        }
                
        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i,j});
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& v, int i, int j, int &m, int &n){
        v[i][j] = true;
        
        if(i > 0 && !v[i-1][j] && h[i][j] <= h[i-1][j])
            dfs(h, v, i-1, j, m, n);
            
        if(i < m - 1 && !v[i+1][j] && h[i][j] <= h[i+1][j])
            dfs(h, v, i+1, j, m, n);
        
        if(j > 0 && !v[i][j-1] && h[i][j] <= h[i][j-1])
            dfs(h, v, i, j-1, m, n);
            
        if(j < n - 1 && !v[i][j+1] && h[i][j] <= h[i][j+1])
            dfs(h, v, i, j+1, m, n);
    }
};

/* Note

Couldn't solve it before 20 minutes or at all. Had to look at solution from neetcode to figure out
how to solve it. My approach before was to have two function one which checked upperLeft and the
the other which check the lowerRight. It could only solve a few cases while missed some edge cases.

The solution from neetcode use two 2d vector of bool for each ocean path. We do a dfs and check if
the next value is less than or equal to the current value. If the next square is possible to go to
one of the ocean then we don't have to call it again.

*/