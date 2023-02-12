/* 994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is
impossible, return -1.

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because
rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int ans = -1;
        int dir[] = {0,-1,0,1,0};
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1)
                    fresh++;

                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                pair<int, int> p = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int row = p.first + dir[j];
                    int col = p.second + dir[j+1];
                    if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()){
                        if(grid[row][col] == 1){
                            q.push({row, col});
                            grid[row][col] = 2;
                            fresh--;
                        }
                    }
                }
            }
            ans++;
        }

        if(fresh != 0)
            return -1;

        return ans == -1?  0 : ans;
    }
};

/* Note

Time: (M x N)
Space: (M x N)

Little rusty so had to look at solution to see the best approach.

int dir[] = {0,-1,0,1,0}

The solution checks the grid for fresh oranges and then bfs through the queue that stores the
rotten oranges and checks the neighbor. bfs and queue

*/