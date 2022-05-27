/* 1309. Decrypt String from Alphabet to Integer Mapping

You are given a string s formed by digits and '#'. We want to map s to English lowercase characters
as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
Return the string formed after mapping.

The test cases are generated so that a unique mapping will always exist. 

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

Example 2:

Input: s = "1326#"
Output: "acz"
 
Constraints:

1 <= s.length <= 1000
s consists of digits and the '#' letter.
s will be a valid string such that mapping is always possible.

*/

class Solution {
public:
    string freqAlphabets(string s) {
        map<string, string> m;
        for(int i = 0; i < 9; i++){
            m[string(1,(char)('1'+i))] = string(1,'a'+i);
        }
        
        for(int i = 0; i <= 16; i++){
            m[to_string(10 + i) + "#"] = string(1,'j' + i);
        }
        
        string res("");
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '#'){
                string temp = s.substr(i-2,3);
                res.insert(0, m[temp]);
                i -= 2;
            }else{
                string temp = string(1,s[i]);
                res.insert(0, m[temp]);
            }
        }
        return res;
    }
};

/* Note

The solution I had was hard to implement. There were some issues with syntax and not propery
casting values. I looked at two solutions and 1 used regex while the other used a for loop
with an if else statement. The one with the for loop was by votrubac and the if statement was
if (i < s.size() - 2 && s[i + 2] == '#') 

*/