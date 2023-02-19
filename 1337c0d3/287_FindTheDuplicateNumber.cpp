/* 287. Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n]
inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or
more times.

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

/* Note

Time: O(n)
Space: O(1)

Couldn't solve it. I solve it using extra memory and didn't use the slow and fast pointers to cycle
through. Couldn't figure out the method needed to solve until seeing the solution.

Use the slow and fast pointers method to figure out the cycle. Since there are two of the same
number then there is a cycle.

*/