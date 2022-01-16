class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};

/* Note

The most voted solution was complicated. They figure out the order of the 
elements then they add it to the result. 

*/