/* 1641. Count Sorted Vowel Strings

Given an integer n, return the number of strings of length n that consist only of vowels
(a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before
s[i+1] in the alphabet.

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].

Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

Example 3:

Input: n = 33
Output: 66045
 
Constraints:

1 <= n <= 50 

*/

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[] = {0,1,1,1,1,1};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 5; j++){
                dp[j] += dp[j-1]; 
            }
        }
        return dp[5];
    }
};

/* Note

Solution from lee215 from the link below:
https://leetcode.com/problems/count-sorted-vowel-strings/discuss/918498/JavaC%2B%2BPython-DP-O(1)-Time-and-Space

Have to look over this solution again. I knew that the solution had to do with dynamic programing,
and the optimal solution had to do with math dealing with permutations or combinations. Did not
the logic or how to implement it.

*/