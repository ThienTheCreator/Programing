/* 763. Partition Labels

You are given a string s. We want to partition the string into as many parts as possible so that
each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant
string should be s.

Return a list of integers representing the size of these parts.

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

Example 2:

Input: s = "eccbbbbdec"
Output: [10]

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int charCount[26] = {0};
        set<int> tempSet = {};
        vector<int> res(0);
        
        for( auto c : s){
            charCount[c - 'a']++;
        }
        
        int tempNum = 0;
        for(auto c : s){
            charCount[c - 'a']--;
            tempSet.insert(c - 'a');
            tempNum++;
            if(charCount[c - 'a'] == 0){
                bool tf = true;
                for(auto val : tempSet){
                    if(charCount[val] != 0){
                        tf = false;
                        break;
                    }
                }
                
                if(tf){
                    res.push_back(tempNum);
                    tempNum = 0;
                    tempSet.clear();
                }
            }
        }
        
        return res;
    }
};

/* Note

I loop through the string twice. Once to keep track of the char count and the second time decrement
the char count. If the char count is zero I would check each char we have seen to see if it is
zero. If the all the char we have seen are zero then add the answer and clear the set and temp
count.

votrubac had an interesting implementation. votrubac's solution:

vector<int> partitionLabels(string S) {
  vector<int> res, pos(26, 0);  
  for (auto i = 0; i < S.size(); ++i) pos[S[i] - 'a'] = i;
  for (auto i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
    idx = max(idx, pos[S[i] - 'a']);
    if (idx == i) res.push_back(i - exchange(last_i, i + 1) + 1);
  }
  return res;
}

The solution keep track of the last index of the characters.

*/