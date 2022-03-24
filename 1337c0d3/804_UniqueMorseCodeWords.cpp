/* 804. Unique Morse Code Words

International Morse Code defines a standard encoding where each letter is mapped to a series of 
dots and dashes, as follows:

'a' maps to ".-",
'b' maps to "-...",
'c' maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
"-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Given an array of strings words where each word can be written as a concatenation of the Morse code
of each letter.

For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and
"-...". We will call such a concatenation the transformation of a word.
Return the number of different transformations among all words we have.

Example 1:

Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".

Example 2:

Input: words = ["a"]
Output: 1
 
Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 12
words[i] consists of lowercase English letters.

*/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string a[] = {".-","-...","-.-.","-..",".","..-.","--.",
                      "....","..",".---","-.-",".-..","--",
                      "-.","---",".--.","--.-",".-.","...",
                      "-","..-","...-",".--","-..-","-.--","--.."};
        set<string> res;
        for(int i = 0; i < words.size(); i++){
            string temp = "";
            for(int j = 0; j < words[i].size(); j++){
                temp += a[words[i][j] - 'a'];
            }
            res.insert(temp);
        }
        return res.size();
    }
};

/* Note

This solution just creates the a new string from the given string by matching the letter to the
morse code. I put the string into a set so see how many unique strings there are. I should have
use an unordered_set because a set is ordered and could slow down the time a little bit.

*/