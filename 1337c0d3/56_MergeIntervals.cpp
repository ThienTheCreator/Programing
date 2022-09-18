/* 56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 
Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        vector<int> temp(2);
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= temp[1]){
                temp[0] = min(intervals[i][0], temp[0]);
                temp[1] = max(intervals[i][1], temp[1]);
            }else{
                res.push_back(temp);
                temp = intervals[i];
            }
        }
        res.push_back(temp);
        
        return res;
    }
};

/* Note

Time: O(n log n)
Space: O(n)

Thought that intervals were sorted when given but it was not. I did not have to take the min but it
was from the previous problem so I just put it there. The solution sorts and keeps a temporary
value to keep track of the interval values. When the next starting value is in between then merge.

*/