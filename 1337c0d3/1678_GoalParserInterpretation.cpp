class Solution {
public:
    string interpret(string command) {
        string res;
        for(int i = 0; i < command.size();i++){
            if(command[i] == 'G'){
                res += "G";
            }else if(command[i] == '('){
                if(command[i+1] == ')'){
                    res += "o";
                    i++;
                }else{
                    res += "al";
                    i += 3;
                }
            }
        }
        return res;
    }
};

/* Note
 
For this one we compare the string and increment by a specific amount.
We only have to compare 1 or two character moving on to the next then
add it to our result string.

*/