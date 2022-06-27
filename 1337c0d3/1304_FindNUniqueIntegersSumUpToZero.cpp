/* 1304. Find N Unique Integers Sum up to Zero

Given an integer n, return any array containing n unique integers such that they add up to 0.

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Example 2:

Input: n = 3
Output: [-1,0,1]

Example 3:

Input: n = 1
Output: [0] 

Constraints:

1 <= n <= 1000

*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        
        if(n % 2 == 1){
            res.push_back(0);
        }
        
        for(int i = 1; i <= n/2; i++){
            res.push_back(i);
            res.push_back(-i);
        }
        
        return res;
    }
};

/* Note

I if it is an odd number I add zero to the array. I add negative and positive number until it
reaches n in size.

lee215 solution is interesting because it takes into account the zero. The number is also two apart
from the previous one.

for (int i = 0; i < n; ++i)
    A[i] = i * 2 - n + 1;

*/