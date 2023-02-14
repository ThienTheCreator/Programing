/* 875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1000000000;

        while(low < high){
            int mid = (low + high) / 2;
            int total = 0;

            for(int i = 0; i < piles.size(); i++){
                total += (piles[i] + mid - 1) / mid;
            }

            if(total > h){
                low = mid + 1;
            }else{
                high = mid;
            }
        }

        return low;
    }
};

/* Note

Time: O(m log n)
Space: O(1)

Couldn't solve this question. I tried to add all the piles together but it did not work because I
think it was too big to store. 

The solution is from lee215:
https://leetcode.com/problems/koko-eating-bananas/solutions/152324/java-c-python-binary-search/?orderBy=most_votes

The solution does a binary search from the middle of the lowest and highest values. It checks if
the middle value when divided and added is smaller or bigger. The binary search is based on this
value.

*/