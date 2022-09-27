/* 371. Sum of Two Integers

Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:

Input: a = 1, b = 2
Output: 3

Example 2:

Input: a = 2, b = 3
Output: 5 

Constraints:

-1000 <= a, b <= 1000

*/

class Solution {
public:
    int getSum(int a, int b) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        int temp;
        while(b){
            temp = a & b;
            a = a ^ b;
            b = (unsigned)temp << 1;
        }
        
        return a;
    }
};

/* Note

Time: O(n)
Space: O(1)

I looked at the solution before solving it. This problems requires you to know specific things
about binary and bitwise operators like XOR.

*/