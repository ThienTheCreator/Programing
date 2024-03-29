/* 150. Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would
always evaluate to a result, and there will not be any division by zero operation.

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 
Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        string temp = "";
        for(int i = 0; i < tokens.size(); i++){
            if(isNumber(tokens[i])){
                st.push(tokens[i]);
                continue;
            }
            
            long long second = stoll(st.top());
            st.pop();
            long long first = stoll(st.top());
            st.pop();
            
            if(tokens[i] == "+"){
                temp = to_string(first + second);
                st.push(temp);
            }else if(tokens[i] == "-"){
                temp = to_string(first - second);
                st.push(temp);                    
            }else if(tokens[i] == "*"){
                temp = to_string(first * second);
                st.push(temp);
            }else if(tokens[i] == "/"){
                temp = to_string(first / second);
                st.push(temp);
            }
        }
        
        return stoi(st.top());
    }

    bool isNumber(string s){
        if(s[0] == '-' && s.size() > 1){
            return true;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i]) == false){
                return false;
            }
        }
        
        return true;
    }
};

/* Note

Time: O(n)
Space: O(n)

Did not finish before 20 minutes but was able to solve without looking at any solutions. 

I looked at the solution by hercle24:

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};

I have not used lambda expressions before to solve any coding challenges.

Also the solution from neetcode:

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> stk;
        
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            
            if (token.size() > 1 || isdigit(token[0])) {
                stk.push(stoi(token));
                continue;
            }
            
            long long int num2 = stk.top();
            stk.pop();
            long long int num1 = stk.top();
            stk.pop();
            
            long long int result = 0;
            if (token == "+") {
                result = num1 + num2;
            } else if (token == "-") {
                result = num1 - num2;
            } else if (token == "*") {
                result = num1 * num2;
            } else {
                result = num1 / num2;
            }
            stk.push(result);
        }
        
        return stk.top();
    }
};

The solution did not require another function to figure out if it is a number from a string.

*/