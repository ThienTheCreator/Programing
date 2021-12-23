/*
An attempt at the solution continue later trying to save space.
*/


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = 1; i < n;i++){
            if(i % 2 == 1){
                swap(nums[i], nums[n+i-1]);
            }else{
                swap(nums[i], nums[n]);
            }
        }
        for(int i = 2*n-2; i >= n; i--){
            if(i % 2 == 1){
                swap(nums[i],nums[2*n-2]);
                cout << i << endl;
            }
        }
        return nums;
    }
};