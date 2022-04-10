/* 832. Flipping an Image

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the
resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
 
Example 1:

Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 
Constraints:

n == image.length
n == image[i].length
1 <= n <= 20
images[i][j] is either 0 or 1.

*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> res(image.size(), vector<int>(image.size()));
                                
        int n = image.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n;j++){
                if(image[i][n - 1 - j] == 1){
                    res[i][j] = 0;
                }else{
                    res[i][j] = 1;
                }
            }
        }
        return res;
    }
};

/* Note

For my solution I did things manually from the reverse to flipping the int value. The solution ran
in 20% faster than other solutions at 11ms. I don't know if leetcode was just paricularly slow
today, but it probably was just my implementation.

Lee215 had the most voted solution. In his he use the reverse from c++ and ^ which is XOR to flip
the int values.

*/