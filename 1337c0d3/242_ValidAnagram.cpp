/* 242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false
 
Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such
a case?

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        if(s.size() != t.size()){
            return false;
        }
        
        int a[26] = {0};
        for(int i = 0; i < s.size(); i++){
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }
        
        for(int i = 0; i < 26; i++){
            if(a[i] < 0){
                return false;
            }
        }
        
        return true;
    }
};

/* Note

Problem instructions were not clear and I did not spend enough time thinking about the problem.
This problem has to do with hashing map. I use an array because it is cleaner than implementing 
hash map and because we know the range of the letters.

*/