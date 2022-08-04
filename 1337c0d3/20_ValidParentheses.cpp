/* 20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the
input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 
Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false
 
Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stac;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(stac.size() == 0){
                    return false;
                }
                
                char c = stac.top();
                stac.pop();
                
                if(s[i] == ')' && c != '('){
                    return false;
                }else if(s[i] == '}' && c != '{'){
                    return false;
                }else if(s[i] == ']' && c != '['){
                    return false;
                }
                
            }else{
                stac.push(s[i]);
            }
            
        }
        
        if(stac.size() != 0){
            return false;
        }
        
        return true;
    }
};

/* Note

I feel like my solution can be shorter using a hashmap. So the solution insert a character if it is
open brackets or braces. When it is a closing bracket or brace then check the top of the stack for
the matching open bracket or brace.

*/