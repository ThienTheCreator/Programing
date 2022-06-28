/* Note

A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of
the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing
parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Example 1:

Input: s = "())"
Output: 1

Example 2:

Input: s = "((("
Output: 3
 
Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'.

*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        int counter = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(counter < 0){
                    counter = 1;
                }else{
                    counter++;
                }
            }else if(s[i] == ')'){
                if(counter <= 0){
                    res++;
                    counter--;
                }else{
                    counter--;
                }
            }
        }
        
        if(counter > 0){
            res += counter;
        }
            
        return res;
    }
};

/* Note

I tried to add when '(' and subtract when ')' at first, but when the ')' came before '(' then it
would increase the answer. My solution would work like this until it reaches zero then it would 
increment the answer if the counter was negative. If the counter is negative and '(' then it would
reset the counter to 1.

lee215 solution:

    int minAddToMakeValid(string S) {
        int left = 0, right = 0;
        for (char c : S)
            if (c == '(')
                right++;
            else if (right > 0)
                right--;
            else
                left++;
        return left + right;
    }

lee's solution keeps two counters for the left and the right. My solution only used one counter so
the solution contains more logic than it needs to have. My solution is messy because it has nested
if statements. One counter keep track when it is greater than 0 and the other counter keep track 
when it is less than zero and the answer is adding the two together.

*/