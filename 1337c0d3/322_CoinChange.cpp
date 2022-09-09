/* 322. Coin Change

You are given an integer array coins representing coins of different denominations and an integer
amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money
cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0
 
Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for(int i = 0; i < amount + 1; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        
        if(dp[amount] == amount + 1)
            return -1;
        
        return dp[amount];
    }
};

/* Note

Time: O(amount * n) n is size of coins
Space: O(amount)

Could not solve it. Did not think about creating a vector the size of the amount + 1. The solution
require creating a vector to the size of the amount + 1. For every element in the vector you check
whether it is the smallest number of coins using the index to keep track.

*/