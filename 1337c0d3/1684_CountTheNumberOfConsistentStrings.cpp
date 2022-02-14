/* 1684. Count the Number of Consistent Strings

You are given a string allowed consisting of distinct characters and an array of strings words. 
A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words. 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.

Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.

*/
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool allow[26] = {};
        int res = words.size();
        for(char i: allowed){
            allow[i-'a'] = true;
        }
        
        for(string i: words){
            for(char j: i){
                if(!allow[j - 'a']){
                    res--;
                    break;
                }
            }
        }
        
        return res;
    }
};

/* Note

I coded my solution similar to the most voted solution. I notice that the solution assigned the
result as the size of words and then decremented it, but I did the opposite. I also used a set
instead of array of bool. They also used the short hand version of the for loop.

*/