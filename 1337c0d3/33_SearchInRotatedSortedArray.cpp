/* 33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k
(1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1],
nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at
pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target
if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:

Input: nums = [1], target = 0
Output: -1
 
Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] > nums[hi]){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        
        int rot = lo;
        lo = 0;
        hi = nums.size() - 1;
        int mid = 0;
        int realMid;
        
        while(lo <= hi){
            mid = (lo + hi) / 2;
            realMid = (mid + rot) % nums.size();
            if(nums[realMid] == target){
                return realMid;
            }
            
            if(nums[realMid] < target){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        
        return -1;
    }
};

/* Note

Could not solve the problem. The solution above is from 
https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14425/Concise-O(log-N)-Binary-search-solution

The solution findest the shift number which is the index of the smallest number. It uses the shift
to find the real middle number of the sorted array. Then the binary search becomes easier when the
middle values is known. 

*/