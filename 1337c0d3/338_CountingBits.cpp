/* 338. Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i]
is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 
Constraints:

0 <= n <= 105
 
Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear
time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

*/

class Solution {
public:
    vector<int> countBits(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        vector<int> res(n + 1, 0);
        
        for(int i = 1; i < res.size(); i++){
            res[i] = res[i/2] + i % 2;
        }
        
        return res;
    }
};

/* Note

Time: O(n)
Space: O(n)

This problem involves dynamic programing. 

The first solution I came up with.

Time: O(n log n)
Space: O(n)

class Solution {
public:
    vector<int> countBits(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        vector<int> res;
        
        for(int i = 0; i <= n; i++){
            int val = 0;
            int temp = i;
            
            while(temp > 0){
                temp = temp & (temp - 1);
                val++;
            }
            
            res.push_back(val);
        }
        
        return res;
    }
};

*/