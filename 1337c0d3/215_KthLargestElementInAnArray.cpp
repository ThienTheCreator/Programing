/* 215. Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        return quickSelect(nums, index, 0, nums.size() - 1);
    }

    int quickSelect(vector<int>& nums, int index, int lo, int hi){
        int pivot = nums[hi];
        int pos = lo;
        for(int i = lo; i < hi; ++i){
            if(nums[i] <= pivot){
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
        swap(nums[pos], nums[hi]);
        if(pos < index){
            return quickSelect(nums, index, pos + 1, hi);
        }
        if(pos > index){
            return quickSelect(nums, index, lo, pos - 1);
        }
        return nums[pos];
    }
};

/* Note

Time: O(n)
Space: O(1)

I originally implemented a priority queue to solve the problem keeping the smallest first in a min
priority queue. I looked at the solution and notice that it solve it another way with quick select.
For quick select you pick a pivot, and sort all elements until the pivot is in the right order by
swaping if left is smaller than pivot.

*/