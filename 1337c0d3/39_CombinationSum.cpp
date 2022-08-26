/* 39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all
unique combinations of candidates where the chosen numbers sum to target. You may return the
combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are
unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150
combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

Input: candidates = [2], target = 1
Output: []
 
Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500

*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> temp;
        vector<vector<int>> res;
        int sum = 0;
        int index = 0;
        
        dfs(candidates, target, sum, index, temp, res);
        
        return res;
    }
    
    void dfs(vector<int>& candidates, int &target, int sum, int index, vector<int> temp, vector<vector<int>> &res){
        if(sum == target){
            res.push_back(temp);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(sum + candidates[i] <= target){
                temp.push_back(candidates[i]);
                dfs(candidates, target, sum + candidates[i], i, temp, res);
                temp.pop_back();
            }
        }
    }
};

/* Note

Time: O(n * target) or O(n)
Space: O(target) or O(1)

Almost solve it before 20 minutes, but had some logic error in dfs. Instead of i, it was index + i. 

solution from neetcode:

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> curr;
        vector<vector<int>> result;
        
        dfs(candidates, target, 0, 0, curr, result);
        return result;
    }
private:
    void dfs(vector<int>& candidates, int target, int sum, int start, vector<int>& curr, vector<vector<int>>& result) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i, curr, result);
            curr.pop_back();
        }
    }
};

Fastest solution on leetcode for C++:

class Solution {
public:
    void findCombination(int ind, int target,  vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        // base case-
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
            }
        
        //pick -
            if(arr[ind] <= target){
                ds.push_back(arr[ind]);
                findCombination(ind, target - arr[ind], arr, ans, ds);
                ds.pop_back();
            }
            
            //not pick-
            findCombination(ind+1, target, arr, ans, ds);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> ds;
        
        findCombination(0, target, candidates, ans, ds);
        
        return ans;
    }
};

*/