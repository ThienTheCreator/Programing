/* 2185. Counting Words With a Given Prefix

You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
 
Constraints:

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.

*/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        int prefLen = pref.size();
        
        for(int i = 0; i < words.size(); i++){
            int j = 0;
            for(j; j < prefLen; j++){
                if(words[i][j] != pref[j]){
                    break;
                }
            }
            if(j == prefLen){
                res++;
            }
        }
        
        return res;
    }
};

/* Note

The solution just loops through the first part of each word and if the char does not match then it
breaks from the loop. We compare j to see if the loop reaches the end of pref size and if it does
then increment the result.

I also saw the fastest solution use a function called mismatch. Need to look at the function more
later. The most voted solution use substr to get the first part of each string and compares it to
the prefix.

*/