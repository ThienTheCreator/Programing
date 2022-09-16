/* 55. Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and
each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which
makes it impossible to reach the last index.
 
Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        int curr = nums[0];
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            curr = max(nums[i], curr - 1);

            if(curr == 0){
                return false;
            }
        }
        
        return true;
    }
};

/* Note

Time: O(n)
Space: O(1)

I did this problem wrong with dynmaic programming creating a vector and a nested for loop which
exceeded the time limit. The solution only involve some variables to keep track of the max distance
that it can travel from one index to the next. When the max distance is zero return false.

*/