/* 128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements
sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 
Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        unordered_map<int, bool> visited;
        for(int i = 0; i < nums.size(); i++){
            visited[nums[i]] = 1;
        }
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res = max(res, helper(nums[i], visited));
        }
        return res;
    }
    int helper(int x, unordered_map<int, bool> &temp){
        if(temp[x] == 1){
            temp[x] = 0;
        }else{
            return 0;
        }
        return 1 + helper(x-1, temp) + helper(x+1, temp);
    }
};

/* Note

I did not realize that I have solve this problem before. I solved this problem again but using a
different way. I used a hashmap and recursion instead of a set and iteratively. 

*/