/* 424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it
to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing
the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
 
Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        int res = 0, maxf = 0;
        unordered_map<int, int> count;
        for(int i = 0; i < s.size(); i++){
            maxf = max(maxf, ++count[s[i]]);
            if(res - maxf < k){
                res++;
            }else{
                count[s[i - res]]--;
            }
        }
        return res;
    }
};

/* Note

Could solve this problem had to look at the answer to see the solution from
https://leetcode.com/problems/longest-repeating-character-replacement/discuss/278271/JavaC%2B%2BPython-Sliding-Window-just-O(n)

lee215 also had a solution which saved some space
    
    int characterReplacement(string s, int k) {
        int maxf = 0, i = 0, n = s.length();
        vector<int> count(26);
        for (int j = 0; j < n; ++j) {
            maxf = max(maxf, ++count[s[j] - 'A']);
            if (j - i + 1 > maxf + k)
                --count[s[i++] - 'A'];
        }
        return n - i;
    }

*/