/* 76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s
such that every character in t (including duplicates) is included in the window. If there is no
such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

*/

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> vec(128, 0);
        int counter = 0;
        for(auto a: t){
            vec[a]++;
            counter++;
        }
        
        int i = 0;
        int j = 0;
        int start = 0;
        int end = 0;
        int resSize = 100001;
        while(j < s.size()){
            if(vec[s[j++]]-- > 0){
                counter--;
            }
            while(counter == 0){
                if(j - i < resSize){
                    resSize = j - i;
                    start = i;
                }
                if(vec[s[i++]]++ == 0){
                    counter++;
                }
            }
        }
        
        if(resSize == 100001){
            return "";
        }
        
        return s.substr(start, resSize);
    }
};

/* Note

I solve it using a hashmap and a function to check if the string t is in the substring. I looked
over the most voted solution from 
https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems

I saw that the solution I had took much longer time to run. It took O(n*m) instead of O(n).

*/