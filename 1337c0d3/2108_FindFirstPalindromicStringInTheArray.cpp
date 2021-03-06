/* 2108. Find First Palindromic String in the Array

Given an array of strings words, return the first palindromic string in the array. If there is no
such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".

Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
 
Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists only of lowercase English letters.

*/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            int j;
            int strLength = words[i].size();
            for(j = 0; j < strLength/2; j++){
                if(words[i][j] != words[i][strLength - 1 - j]){
                    break;
                }
            }
            
            if(j == strLength/2){
                return words[i];
            }
        }
        
        return "";
    }
};

/* Note

The solution compare the start and the back char then move towards the middle for each string. 

*/