/* 84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each
bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4
 
Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.push_back(0);
        vector<int> vec;
        
        for(int i = 0; i < heights.size(); i++){
            while(vec.size() > 0 && heights[vec.back()] >= heights[i]){
                int h = heights[vec.back()];
                vec.pop_back();
                
                int prev = vec.size() > 0 ? vec.back() : -1;
                if( h * (i - prev - 1) > res)
                    res = h * (i - prev - 1);
            }
            
            vec.push_back(i);
        }
        
        return res;
    }
};

/* Note

Time: O(n)
Space: O(n)

Wasn't able to solve question. Had to look at someone else solution to figure out how to do it.

Solution is by sipiprotoss5 from:
https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28905/My-concise-C%2B%2B-solution-AC-90-ms

The solution involve keeping track of the index in a stack. Vector is used like a stack to avoid
pairing two int. If a previous value in the stack is greater than the current value we pop it from
the stack and calculate the area.

*/