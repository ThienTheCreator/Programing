/* 1704. Determine if String Halves Are Alike

You are given a string s of even length. Split this string into two halves of equal lengths, and
let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels
('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U').
Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not
alike. Notice that the vowel o is counted twice.
 
Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.

*/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0, count2 = 0;
        int half = s.size()/2;
        char c[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; 
        for(int i = 0; i < half; i++){
            bool tf = find(begin(c), end(c), s[i]) != end(c);
            if(tf){
                count1++;
            }
            tf = find(begin(c), end(c), s[half+i]) != end(c);
            if(tf){
                count2++;
            }
        }
        return count1 == count2;
    }
};

/* Note

This solution counts the first half and second half of the array for the vowels with find().
If the counts are equal return true else return false. If we convert to lowercase character, it
seems we can lower the time a little bit.

*/