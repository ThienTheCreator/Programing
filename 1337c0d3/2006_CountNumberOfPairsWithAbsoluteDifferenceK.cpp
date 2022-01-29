/* 2006. Count Number of Pairs With Absolute Difference K

Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.
 

Example 1:

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]

Example 2:

Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.
Example 3:

Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
1 <= k <= 99

*/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int arr[101] = {0};
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i]]++;
        }
        
        
        int res = 0;
        for(int i = k + 1; i < 101; i++){
            res += arr[i] * arr[i-k];
        }
        
        return res;
    }
};

/* Note

For the solution, I looked at the discussion to see if there is sorting.
The solution use a array to keep track of the frequency of words.
To get the answer we start at k+1 for i because the constraints start at 1,
then we multiply by i by i-k and added to our ans and iterate forward. 
i - (i-k) = k so we can pair i and i - k by multiplying them. 

*/