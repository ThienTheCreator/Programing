/* 567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

xample 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 
Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        int m = s1.size();
        int n = s2.size();
        
        if(m > n){
            return false;
        }
        
        int c[26] = {0};
        for(int i = 0; i < m; i++){
            c[s1[i] - 'a']++;
            c[s2[i] - 'a']--;
        }
          
        if(isPermutation(c))
            return true;
        
        for(int i = m; i < n; i++){
            c[s2[i - m] - 'a']++;
            c[s2[i] - 'a']--;
            if(isPermutation(c)){
                return true;
            }
        }
        
        return false;
    }
    
    bool isPermutation(int (&arr)[26]){
        for(int i = 0; i < 26; i++){
            if(arr[i] != 0)
                return false;
        }
        return true;
    }
};

/* Note

Time: O(n)
Space: O(1)

Wasn't able to solve this problem within 20 minutes. Was stuck because code was bad should have
made functions to make things easier. This solution is a sliding window which add from the back and
subtracts from the front.

*/