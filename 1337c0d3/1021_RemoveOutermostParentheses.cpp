/* 1021. Remove Outermost Parentheses

A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid
parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to
split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk,
where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))",
with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 
Constraints:

1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.

*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        char temp = ' ';
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                count++; 
            }else{
                count--;
            }
            
            if(temp == ' '){
                temp = s[i];
            }else if(count == 0){
                temp = ' ';
            }else{
                res += s[i];
            }
        }
        return res;
    }
};

/* Note

I went through and compare each individual character. I use a int and char to keep track of the
position. 

I looked at lee215 solution and he did not use a char but instead use if statement to compare the
count.

lee215 solution:

string removeOuterParentheses(string S) {
    string res;
    int opened = 0;
    for (char c : S) {
        if (c == '(' && opened++ > 0) res += c;
        if (c == ')' && opened-- > 1) res += c;
    }
    return res;
}

*/