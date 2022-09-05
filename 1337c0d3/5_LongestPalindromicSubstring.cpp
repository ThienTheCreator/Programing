/* 5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.
 
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"
 
Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

*/

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        
        for(int i = 0; i < s.size(); i++){
            expand(s, i, i, res);
            expand(s, i, i+1, res);
        }
        
        return res;
    }
    
    void expand(string& s, int i, int j, string& res){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        
        if(j - i > 0){
            i++;
            j--;
        }
        
        if(res.size() < j - i + 1){
            res = s.substr(i, j - i + 1);
        }
    }
};

/* Note

Time: O(n^2) n is the length of the string
Space: O(1)

Couldn't solve in 20 minutes. The solution involve comparing what is behind and infront of a
character. Traverse each character and 

*/