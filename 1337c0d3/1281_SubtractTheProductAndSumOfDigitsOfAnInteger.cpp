/* 1281. Subtract the Product and Sum of Digits of an Integer

Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 

Example 1:

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15

Example 2:

Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21
 

Constraints:

1 <= n <= 10^5

*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int tempProduct = 1;
        int tempSum = 0;
        int temp;
        while(n != 0){
            temp = n % 10;
            n /= 10;
            tempProduct *= temp;
            tempSum += temp;
        }
        return tempProduct - tempSum;
    }
};

/* Note

Solution is similar to the most vote solution, but most voted solution did not
have the temp variable. They directly did the n % 10 either add or multiply. 

*/