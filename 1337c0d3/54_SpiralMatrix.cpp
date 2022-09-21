/* 54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        vector<int> res;
        
        int height = matrix.size();
        int width = matrix[0].size();
        
        int row = 0; 
        int col = 0;
        
        int direction = 0;
        
        while(height > 0 && width > 0){
            int x = 0, y = 0;
            
            if(direction == 0){
                y = 1;
            }else if(direction == 1){
                x = 1;
            }else if(direction == 2){
                y = -1;
            }else if(direction == 3){
                x = -1;
            }
            
            int s;
            if(x != 0){
                s = height;
                width--;
            }else{
                s = width;
                height--;
            }
            
            for(int i = 0; i < s; i++){
                res.push_back(matrix[row][col]);
                row += x;
                col += y;
            }
            row -= x;
            col -= y;
            
            if(direction == 0){
                row++;
            }else if(direction == 1){
                col--;
            }else if(direction == 2){
                row--;
            }else if(direction == 3){
                col++;
            }
            
            direction = (direction + 1) % 4;
        }
        return res;
    }
};

/* Note

Time: O(m * n)
Space: O(m * n)

Spent more time on this problem than I should have. My solution keeps track of the height and width
and the direction. The solution would go to the next spiral element if it reaches an edge and
decrement the opposite height or width. It would have been easier if I just keep track of the four
edges.  The solution from neetcode below shows how to do this.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        
        vector<int> result;
        
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
            }
            bottom--;
            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        
        return result;
    }
};

*/