/* 1329. Sort the Matrix Diagonally

A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

Example 1:

Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

Example 2:

Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 
Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector <int>> vec(mat.size(), vector<int>(mat[0].size()));
        int r = vec.size();
        int c = vec[0].size();
        int x = 0;
        int y = 0;
        vector<int> tempVec;
        for(int i = 0; i < r + c - 1; i++){
            if(c - 1 - i >= 0){
                x = 0;
                y = c - 1 - i;
            }else{
                x = i + 1 - c;
                y = 0;
            }
            
            int tempX = x;
            int tempY = y;
            
            tempVec.clear();
            while(x < r && y < c){
                tempVec.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(tempVec.begin(),tempVec.end());
            
            x = tempX;
            y = tempY;
            for(int tempInt: tempVec){
                vec[x][y] = tempInt;
                x++;
                y++;
            }
        }
        return vec;
    }
};

/* Note

The most voted solution map an int with a priotiy queue. They use i - j diagonal rows to each 
other. Then they a nested for loop like normal to get lowest element from the priority queue with 
the associated row.

*/