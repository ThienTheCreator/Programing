/* 22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed
parentheses.
 
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]
 
Constraints:

1 <= n <= 8

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", n, 0, 0);
        return res;
    }
    
    void generate(vector<string> &res, string s, int n, int open, int close){   
        if(s.size() == n * 2 && open == close){
            res.push_back(s);
        }
        
        if(open < n){
            generate(res, s + "(", n, open + 1, close);
        }
        
        if(open > close){
            generate(res, s + ")", n, open, close + 1);
        }
    }
};

/*

Time: O(2^n)
Space: O(n)

Was able to solve but spent more than 20 minutes because code had error in it. I looked at one
solution and they incorporated n into open and close. 

*/