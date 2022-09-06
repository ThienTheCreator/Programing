/* 647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            solve(s, i, i, res);
            solve(s, i, i+1, res);
        }
        
        return res;
    }
    
    void solve(string& s, int i, int j, int& res){
        if(i < 0 || j >= s.size())
            return;
        
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            res++;
            i--;
            j++;
        }
    }
};

/* Note

Time: O(n^2)
Space: O(1)

This solution was similar to finding the largest substring, but instead we just count the number of
possible substrings. Calculate a palindromic substings starting with the same char or two chars.

*/