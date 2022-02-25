/* 1913. Maximum Product Difference Between Two Pairs

The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).

For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
Given an integer array nums, choose four distinct indices w, x, y, and z such that the product 
difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.

Return the maximum such product difference.

 

Example 1:

Input: nums = [5,6,2,7,4]
Output: 34
Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the 
second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.
Example 2:

Input: nums = [4,2,5,9,7,4,8]
Output: 64
Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the 
second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.
 

Constraints:

4 <= nums.length <= 104
1 <= nums[i] <= 104

*/
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int a[4];
        priority_queue<int> que;
        for(int i = 0; i < 4; i++){
            que.push(nums[i]);
        }
        for(int i = 3; i >= 0; i--){
            a[i] = que.top();
            que.pop();
        }
        for(int i = 4; i < nums.size(); i++){
            if(nums[i] <= a[0]){
                a[1] = a[0];
                a[0] = nums[i];
            }else if(nums[i] < a[1]){
                a[1] = nums[i];
            }else if(nums[i] >= a[3]){
                a[2] = a[3];
                a[3] = nums[i];
            }else if(nums[i] > a[2]){
                a[2] = nums[i];
            }
        }
        return (a[3] * a[2]) - (a[1] * a[0]);
    }
};

/* Note

I use a priority_queue to get the first four elements of the original vector in sorted order.
Get the two largest and two smallest numbers from the vector. The first two element of the array a
stores the two smallest value and the last two elements of a store the largest two value. If value
is smaller than the the smallest then move the value to second smallest and replace smallest with
value. If it is bigger then the smallest but smaller than then second smallest then just replace
the second smallest value. The bigger values in the array work similar to this.

*/