/* 238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of
all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 
Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not
count as extra space for space complexity analysis.)

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> fromStart(nums.size());
        vector<int> fromEnd(nums.size());
        
        fromStart[0] = nums[0];
        fromEnd[nums.size() - 1] = 1;
        for(int i = 1; i < nums.size(); i++){
            fromStart[i] = fromStart[i-1] * nums[i];
        }
        
        for(int i = nums.size() - 2; i >= 0; i--){
            fromEnd[i] = fromEnd[i+1] * nums[i+1];
        }
        
        res[0] = fromEnd[0];
        for(int i = 1; i < nums.size(); i++){
            res[i] = fromStart[i-1] * fromEnd[i];
        }
        
        return res;
    }
};

/* Note

For this solution I had to look at the discussion to figure out the pattern. You would have two
array to calculate the product from the begining and from the end. 

*/