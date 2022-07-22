/* 347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return
the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]
 
Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 
Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's
size.

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        
        for(int i = 0; i < nums.size(); i++){
            um[nums[i]] += 1;
        }
        
        vector<vector<int>> temp(nums.size()+1);
        for(auto i: um){
            temp[i.second].push_back(i.first);
        }
        
        vector<int> res;
        for(int i = temp.size() - 1; i >= 0; i--){
            if(temp[i].size() > 0){
                for(int j = 0; j < temp[i].size(); j++){
                    res.push_back(temp[i][j]);
                    if(res.size() == k){
                        return res;
                    }
                }
            }
        }
        
        return res;
    }
};

/* Note

First calculate the frequency using a hashmap. Then you can use a few technique to sort the values
like priority queue, bucket sort, and quickselect.

The solution below was the fasted I saw. It is easier to implement and use less memory.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        
        for(int i = 0; i < nums.size(); i++){
            um[nums[i]] += 1;
        }
        
        priority_queue <pair<int, int>> pq;
        for(auto x: um){
            pq.push({x.second,x.first});
        }
        
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }        
        
        return res;
    }
};

*/