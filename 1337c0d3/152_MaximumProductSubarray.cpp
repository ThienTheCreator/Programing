/* 152. Maximum Product Subarray

Given an integer array nums, find a contiguous non-empty subarray within the array that has the
largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 
Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int res = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            int temp = currMax;
            
            currMax = max(max(currMin * nums[i], currMax * nums[i]), nums[i]);
            currMin = min(min(currMin * nums[i], temp * nums[i]), nums[i]);
            
            res = max(res, currMax);
        }
        
        return res;
    }
};

/* Note

Time: O(n)
Space: O(1)

Could not solve this. To solve this we keep track of the current maximum and current minimum
values. The minimum is used usedful to keep track of multiplying two negatives. I was stuck on how
to solve for negative values and did not know that zero would reset product.

*/