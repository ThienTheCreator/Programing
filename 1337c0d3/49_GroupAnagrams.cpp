/* 49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any
order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]
 
Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> tempStrs(strs.size());
        for(int i = 0; i < strs.size(); i++){
            tempStrs[i] = strs[i];
            sort(tempStrs[i].begin(), tempStrs[i].end());
        }
        
        for(int i = 0; i < tempStrs.size(); i++){
            cout << tempStrs[i] << endl;
        }
        
        vector<vector<string>> res;
        unordered_map<string, int> m;
        for(int i = 0; i < strs.size(); i++){
            string str;
            
            vector<string> temp;
            if(m[tempStrs[i]] == 0){
                m[tempStrs[i]] = 1;
                temp.push_back(strs[i]);
                str = tempStrs[i];
            }else{
                continue;
            }
            
            for(int j = i + 1; j < strs.size(); j++){
                if(str == tempStrs[j]){
                    temp.push_back(strs[j]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

/* Note

My solution sorts the all the strings and puts its into an temporary array. Then it loops through
the other elements to see if it matches and then adds the original word to the result vector.

This was the fastest solution in C++:

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string& s:strs){
            string t = countingSort(s);
            mp[t].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(mp.size());
        for(auto& x: mp)
            res.push_back(move(x.second));
        return res;
    }
    string countingSort(string s){
        int Counter[26] = {0};
        for(int c = 0; c < s.size(); c++)
            Counter[s[c] - 'a']++;
        s = "";
        for(int c = 0; c < 26; c++)
            s += string(Counter[c],'a' + c);
        return s;
    }
};

*/