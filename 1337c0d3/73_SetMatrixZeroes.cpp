/* 73. Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]] 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 
Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool top = false;
        bool left = false;
        
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                left = true;
                break;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0){
                top = true;
                break;
            }
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n; i++){
            if(matrix[0][i] == 0){
                for(int j = 1; j < m; j++){
                    matrix[j][i] = 0;
                }
            }
        }
        
        if(left){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        
        if(top){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
    }
};

/* Note

Time: O(m * n)
Space: O(1)

Took some time to come up with this solution but was able to solve with O(m + n) space. The
solution involving keeping track of the zeros by storing the zeros on the first row and column.

The first solution I came up with;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<bool> row(m);
        vector<bool> col(n);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        
        for(int i = 0; i < row.size(); i++){
            if(row[i] == true){
                for(int j = 0; j < col.size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < col.size(); i++){
            if(col[i] == true){
                for(int j = 0; j < row.size(); j++){
                    matrix[j][i] = 0;
                }
            }
        }
    }
};

*/