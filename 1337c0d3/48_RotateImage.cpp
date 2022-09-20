/* 48. Rotate Image

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 
Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        int n = matrix.size();
        int m = n - 1;
        
        for(int i = 0; i < (n+1)/2; i++){
            for(int j = i; j < n - i - 1; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[m-j][i];
                matrix[m-j][i] = matrix[m-i][m-j];
                matrix[m-i][m-j] = matrix[j][m-i];
                matrix[j][m-i] = temp;
            }
        }
    }
};

/*

Time: O(n^2)
Space: O(1)

Did not solve in the given amount to time. The solution I saw from neetcode did swaping and reverse
the rows after. 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

*/