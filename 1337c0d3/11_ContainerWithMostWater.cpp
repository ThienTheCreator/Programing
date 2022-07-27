/* 11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the
two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the
most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1
 
Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(0);
        
        int lo = 0;
        int hi = height.size() - 1;
        int s = height.size() - 1;
        
        int m = 0;
        int res = 0;
        while(lo < hi){
            m = min(height[lo], height[hi]);
            res = max(res, m * s);
            if(height[lo] < height[hi]){
                lo++;
            }else{
                hi--;
            }
            s--;
        }
        return res;
    }
};

/* Note

This solution has two pointers one pointer at the begining and one at the end. We move the pointers
to meet each other and calculate the area and take the max area.

*/