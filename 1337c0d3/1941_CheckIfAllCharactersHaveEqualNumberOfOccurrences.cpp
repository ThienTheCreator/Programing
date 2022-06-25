/* 1941. Check if All Characters Have Equal Number of Occurrences

Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:

Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Example 2:

Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
 
Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n[26] = {0};
        for(int i = 0; i < s.size(); i++){
            n[s[i] - 'a']++;
        }
        
        int freq = n[s[0] - 'a'];
        for(int i = 0; i < 26; i++){
            if(n[i] != 0 && n[i] != freq){
                return false;
            }
        }
        
        return true;
    }
};

/* Note

This solution makes an array of int to keep track of 26 letters in the alphabet. It loops through
the string and increment an index in the array based on the letter. The we use the frequency of the
first letter in the string and loop through all the letter frequency that is greater than 0 to see
if it is equal.

*/