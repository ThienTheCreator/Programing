/* 1221. Split a String in Balanced Strings

Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it in the maximum amount of balanced strings.

Return the maximum amount of split balanced strings.

 
Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Example 2:

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".
 

Constraints:

1 <= s.length <= 1000
s[i] is either 'L' or 'R'.
s is a balanced string.

*/


class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int temp = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R'){
                temp++;
            }else{
                temp--;
            }
            if(temp == 0){
                res++;
            }
        }
        return res;
    }
};

/* Note

For this one we just increment if it a temp variable if it is R
and decrement the temp variable if it is L. When the temp variable 
is 0 then we increment the result. Try using a stack but I would have
to write the cases if it is R or L.

*/