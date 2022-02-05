/* 1588. Sum of All Odd Length Subarrays

Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.

 
Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
Example 2:

Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
Example 3:

Input: arr = [10,11,12]
Output: 66
 

Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000

*/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0; 
        for(int i = 0; i < arr.size(); i++){
            int start = arr.size()-i;
            int end = i+1;
            int total = start * end;
            res += (total + 1)/2 * arr[i];
        }
        return res;
    }
};

/* Note

I coded the solution again after watching a video about a pattern. We want to figure out how many
sub arrays are counted when we iterate through the array. For example [1,2,3,4,5], 
1  element * 5 subarray = 5 elements total
2 elements * 4 subarray = 8 elements total
3 elements * 3 subarray = 9 elements total
4 elements * 2 subarray = 8 elements total 
5 elements * 1 subarray = 5 elements total

if we add 1 and divide by 2 we should get the number of time the elements show  up in the final 
solution. Then we can muliply this array and the original array to get our solution 
[3,4,5,4,3] * [1,2,3,4,5] = [3,8,15,16,15]
3 + 8 + 15 + 16 + 15 = 57
 
*/