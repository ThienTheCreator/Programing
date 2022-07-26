/* 15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j,
i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 
Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size()-2; i++){
            if(i == 0 || nums[i-1] != nums[i]){
                int lo = i + 1, hi = nums.size() - 1, s = -nums[i];
                
                while(lo < hi){
                    if(nums[lo] + nums[hi] == s){
                        vector<int> temp = {nums[i], nums[lo], nums[hi]};
                        res.push_back(temp);
                        
                        while(lo < hi && nums[lo] == nums[lo+1]){
                            lo++;
                        }
                        
                        while(lo < hi && nums[hi-1] == nums[hi]){
                            hi--;
                        }
                        
                        lo++;
                        hi--;
                   
                    }else if(nums[lo] + nums[hi] > s){
                        hi--;
                    }else{
                        lo++;
                    }
                }
            }
        }
        return res;
    }
};

/* Note

I tried to brute force the solution but it exceeded the time limit. The solution I code was by
shpolsky https://leetcode.com/problems/3sum/discuss/7380/Concise-O(N2)-Java-solution. 

I got stuck with the if and while conditions so I had to look at the solution to see how to solve
it.

*/