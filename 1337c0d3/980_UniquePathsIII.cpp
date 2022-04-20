/* 980. Unique Paths III

You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk
over every non-obstacle square exactly once.

Example 1:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:

Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.

*/

class Solution {
public:
    int pathSize = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int res = 0;
        int xStart, yStart, xEnd, yEnd;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    xStart = i;
                    yStart = j;
                }else if(grid[i][j] == 2){
                    xEnd = i;
                    yEnd = j;
                }else if(grid[i][j] == 0){
                    pathSize++;
                }
            }
        }
        
        pathSize++;
        
        return dfs(xStart, yStart, 0, grid);
    }
    
    int dfs(int x, int y, int count, vector<vector<int>> grid){
        if(x < 0 || x > grid.size() - 1 || y < 0 || y > grid[x].size() - 1 || grid[x][y] == -1 || count > pathSize){
            return 0;
        }
        
        if(count == pathSize && grid[x][y] == 2){
            return 1;
        }
        
        int temp = 0;
        grid[x][y] = -1;
        
        temp += dfs(x + 1, y, count + 1, grid);
        temp += dfs(x, y + 1, count + 1, grid);
        temp += dfs(x - 1, y, count + 1, grid);
        temp += dfs(x, y - 1, count + 1, grid);
        
        return temp;
    }
};

/* Note

This one took me a while to to solve. I try to do it iterative at first, but it seems more
complicated and inefficient than recursive method. This solution ran pretty slow. Might look at
this later.

*/