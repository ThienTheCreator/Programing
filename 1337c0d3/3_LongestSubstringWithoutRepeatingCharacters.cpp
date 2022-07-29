/* 3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        vector<int> letter(256, -1);
        int start = -1;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(letter[s[i]] > start){
                start = letter[s[i]];
            }
            
            letter[s[i]] = i;
            res = max(res, i - start);
        }
        return res;
    }
};

/* Note

The solution is from 
https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1737/C%2B%2B-code-in-9-lines.

I try to code the solution without looking at and I was successful using a set, but it was somewhat
slow. I also try to code the solution from above after looking at it once, but the logic was wrong.
Need to write out the logic before coding it.

*/