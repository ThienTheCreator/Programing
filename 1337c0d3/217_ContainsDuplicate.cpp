/* 217. Contains Duplicate



*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] += 1;
            if(m[nums[i]] > 1){
                return true;
            }
        }
        
        return false;
    }
};

/* Note

My solution used m.count() with and if else statement which was slower because it would have to
through the else also instead of just the if statement. 

ios_base::sync_with_stdio(0)    C++ streams are synchronize to the c streams
cin.tie(0);                     tie() flushes cin before cout
cout.tie(0);                    isn't necessary because cout is generally tie to null

*/