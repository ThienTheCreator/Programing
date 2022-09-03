/* 213. House Robber II



*/

class Solution {
    int robber(vector<int> nums, int start, int end){
        int prev = 0;
        int curr = 0;
        int next = 0;
        
        for(int i = start; i < end; i++){
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        
        return curr;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int path1 = robber(nums, 0, nums.size() - 1);
        int path2 = robber(nums, 1, nums.size());
        
        return max(path1, path2);
    }
};

/* Note

Time: O(n)
Space: O(1)

Was able to solve this question in 20 minutes, but solution was not clean. Spent a little bit more
time to clean up the code. Used the code for house robber 1 to find the paths from different
ranges. One path leaves out the end and the other leaves out the beginning.

*/