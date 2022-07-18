/* 942. DI String Match

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as
a string s of length n where:

s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it. If there are multiple valid
permutations perm, return any of them.

Example 1:

Input: s = "IDID"
Output: [0,4,1,3,2]

Example 2:

Input: s = "III"
Output: [0,1,2,3]

Example 3:

Input: s = "DDI"
Output: [3,2,0,1]
 
Constraints:

1 <= s.length <= 105
s[i] is either 'I' or 'D'.

*/

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0;
        int high = s.size();
        vector<int> res(s.size()+1);
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'I'){
                res[i] = low;
                low++;
            }else{
                res[i] = high;
                high--;
            }
        }
        res[s.size()] = high;
        
        return res;
    }
};

/* Note

My solution starts with the highest or the lowest numbers and works its way to the middle. I saw a
solution where you start in the middle and generate outwards. 

*/