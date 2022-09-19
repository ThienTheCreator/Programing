/* 435. Non-overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum
number of intervals you need to remove to make the rest of the intervals non-overlapping. 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 
Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int res = 0;
        for(int i = 0; i < intervals.size() - 1; i++){
            if(intervals[i][1] > intervals[i+1][0]){
                if(intervals[i][1] < intervals[i+1][1]){
                    intervals[i+1] = intervals[i];
                }
                res++;
            }
        }
        return res;
    }
};

/* Note

Did not solve in 20 minutes but was close. Was stuck on the if conditions to solve the solution.
The solution compares if the next value is between the interval. If the starting intervals values
are the same then take the intervals that ends with the smaller value.

*/