/* 139. Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a
space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 
Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(auto w: wordDict){
            words.insert(w);
        }
        
        vector<bool> dp(s.size() + 1);
        dp[0] = 1;
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                if(dp[j]){
                    string word = s.substr(j, i-j);
                    if(words.find(word) != words.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};

/* Note

Time: O(n^3)
Space: O(n)

Could not solve this. The solution require a dynamic programing, but I was stuck on the dynamic
programing part. Start at the begining of s and move forward. For each position of s check in our
memory to see if we have a sub string that is included in it.

*/