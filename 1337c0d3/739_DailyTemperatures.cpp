/* 739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer
such that answer[i] is the number of days you have to wait after the ith day to get a warmer
temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        vector<int> res(temperatures.size());
        stack<pair<int, int>> st;
        
        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && st.top().first < temperatures[i]){
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        
        return res;
    }
};

/*

Time: O(n)
Space: O(n)

Did not realize this problem was a stack a first. I thought it could be a dynamic programming
problem or a problem using double-ended queue. Was able to solve it before time ended. For this
solution I store the value and index in a stack. I use the stack to compare the value and then pop
base on it. 

*/