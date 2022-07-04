/* 1347. Minimum Number of Steps to Make Two Strings Anagram

You are given two strings of the same length s and t. In one step you can choose any character of
t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same)
ordering.

Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.

Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
 
Constraints:

1 <= s.length <= 5 * 104
s.length == t.length
s and t consist of lowercase English letters only.

*/

class Solution {
public:
    int minSteps(string s, string t) {
        int c[26] = {0};
        
        for(int i = 0; i < s.size(); i++){
            c[s[i] - 'a']++;
            c[t[i] - 'a']--;
        }
        
        int res = 0;
        
        for(int i = 0; i < 26; i++){
            res += abs(c[i]);
        }
        
        return res/2;
    }
};

/* Note

This solution to this one is to count the char for both strings. One string will increment while
the other string will decrement the frequency of the characters. At the end we just add the
absolute value to the result and divide by 2. Alternatively we could use a if loop to add the
result so that we do not have to divide by 2. The reason we divided by 2 is that when we switch the
char one char will become the other so 2 wrong char will become 0 wrong char. 

*/