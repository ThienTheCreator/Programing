/* 295. Find Median from Data Stream

The median is the middle value in an ordered integer list. If the size of the list is even, there
is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual
answer will be accepted.

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 
Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 
Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your
solution? 
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize
your solution?

*/

class MedianFinder {
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
public:
    MedianFinder() {
        ios_base::sync_with_stdio(0);
    }
    
    void addNum(int num) {
        high.push(num);
        if(low.size() + 1 < high.size()){
            low.push(high.top());
            high.pop();
        }else if(low.size() && low.top() > high.top()){
            int temp1 = low.top();
            int temp2 = high.top();
            low.pop();
            high.pop();
            low.push(temp2);
            high.push(temp1);
        }
    }
    
    double findMedian() {
        if((low.size() + high.size()) % 2){
            return high.top();
        }
        
        return (low.top() + high.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


/* Note

n is the of times addNumber is called
Time: O(n)
Space: O(n)

Uses a priority queue to keep track of the data stream. The low priority queue stores the first
half which is sorted from low to high. The high priority queue stores the second half which is
sorted from high to low. The top of low and high should show the middle numbers.

I found a simpler solution from StefanPochmann:
https://leetcode.com/problems/find-median-from-data-stream/discuss/74062/Short-simple-JavaC%2B%2BPython-O(log-n)-%2B-O(1)

class MedianFinder {
    priority_queue<long> small, large;
public:

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};

It is smart that this solution stores negative numbers in the second priority queue so they did
not have to create a priority to go from high to low.

*/
