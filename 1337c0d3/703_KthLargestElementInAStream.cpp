/* 703. Kth Largest Element in a Stream

Design a class to find the kth largest element in a stream. Note that it is the kth largest element
in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers
nums.

int add(int val) Appends the integer val to the stream and returns the element representing the kth
largest element in the stream. 

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

Constraints:

1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for the kth element.

*/

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int kthIndex;
public:
    KthLargest(int k, vector<int>& nums) {
        kthIndex = k;
        for(int i = 0; i < nums.size(); ++i){
            pq.push(nums[i]);
            while(pq.size() > kthIndex){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > kthIndex){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/* Note

Time: O(n log n + m log k) -> n = length of nums, m = add calls
Space: O(n)

Could not solve within time limit. Did not know what data structure was sorted so had to look it up
and also look up the syntax in C++. Used a heap a first, but then figure out it was not sorted. The
solution keep track of the first kth largest value and would insert and pop the larger than kth
element.

*/