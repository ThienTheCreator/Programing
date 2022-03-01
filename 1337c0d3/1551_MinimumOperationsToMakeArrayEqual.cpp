/* 1551. Minimum Operations to Make Array Equal

You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i 
(i.e., 0 <= i < n).

In one operation, you can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x]
and add 1 to arr[y] (i.e., perform arr[x] -=1 and arr[y] += 1). The goal is to make all the 
elements of the array equal. It is guaranteed that all the elements of the array can be made equal 
using some operations.

Given an integer n, the length of the array, return the minimum number of operations needed to make
all the elements of arr equal.

Example 1:

Input: n = 3
Output: 2
Explanation: arr = [1, 3, 5]
First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
Example 2:

Input: n = 6
Output: 9
 

Constraints:

1 <= n <= 104

*/

class Solution {
public:
    int minOperations(int n) {
        return n * n / 4;
    }
};

/* Note

For this one I just looked at the solution after trying it out for 5 minutes. This problem involves
math. I think I need to draw it out next time. If n is odd then we can pair the first half with the
second half to the middle number. 

For example, n = 5, we have [1, 3, 5, 7, 9]. 
5 - 1 = 4, 5 - 3 = 2, then 4 + 2 = 6 we can use 2 * (x) * (x+1) / 2
now we have to find the value for x from n, 
since we just want the first half then x = (n - 1) / 2
then our formula becomes n
( ( n - 1 ) / 2 ) * ( (n - 1) / 2 + 1 )
= ( n ^ 2 - 2n + 1) / 4 + ( n - 1) / 2
= ( n ^ 2 - 2n + 1) / 4 + 2( n - 1) / 4
= ( n ^ 2 - 1) / 4
we can simplified it further since we know it is odd 
( n ^ 2 ) / 4 

when it is even 
let n = 4, [1, 3, 5, 7]
3 + 1
The sum of odd number formula is x^2
x = n/2
we simplified the formula if it is even to
( n ^ 2 ) / 4

*/