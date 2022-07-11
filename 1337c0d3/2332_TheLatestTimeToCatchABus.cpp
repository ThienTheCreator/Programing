/* 2332. The Latest Time to Catch a Bus

You are given a 0-indexed integer array buses of length n, where buses[i] represents the departure
time of the ith bus. You are also given a 0-indexed integer array passengers of length m, where
passengers[j] represents the arrival time of the jth passenger. All bus departure times are unique.
All passenger arrival times are unique.

You are given an integer capacity, which represents the maximum number of passengers that can get
on each bus.

The passengers will get on the next available bus. You can get on a bus that will depart at x
minutes if you arrive at y minutes where y <= x, and the bus is not full. Passengers with the
earliest arrival times get on the bus first.

Return the latest time you may arrive at the bus station to catch a bus. You cannot arrive at the
same time as another passenger.

Note: The arrays buses and passengers are not necessarily sorted. 

Example 1:

Input: buses = [10,20], passengers = [2,17,18,19], capacity = 2
Output: 16
Explanation: 
The 1st bus departs with the 1st passenger. 
The 2nd bus departs with you and the 2nd passenger.
Note that you must not arrive at the same time as the passengers, which is why you must arrive before the 2nd passenger to catch the bus.

Example 2:

Input: buses = [20,30,10], passengers = [19,13,26,4,25,11,21], capacity = 2
Output: 20
Explanation: 
The 1st bus departs with the 4th passenger. 
The 2nd bus departs with the 6th and 2nd passengers.
The 3rd bus departs with the 1st passenger and you.

Constraints:

n == buses.length
m == passengers.length
1 <= n, m, capacity <= 105
2 <= buses[i], passengers[i] <= 109
Each element in buses is unique.
Each element in passengers is unique.

*/

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        unordered_map<int, bool> m;
        int res = 0;
        int p = 0;
        
        for(int i = 0; i < passengers.size(); i++){
            m[passengers[i]] = 1;
        }
        
        for(int i = 0; i < buses.size(); i++){
            int count = 0;
            while(p < passengers.size() && count < capacity && passengers[p] <= buses[i]){
                if(!m.count(passengers[p] - 1)){
                    res = passengers[p] - 1;
                }
                p++;
                count++;
            }
            
            if(count < capacity){
                for(int j = buses[i]; j >= 1; j--){
                    if(!m.count(j)){
                        res = max(j, res);
                        break;
                    }
                }
            }
        }

        return res;
    }
};

/* Note

I spent a lot of time on this question which I don't think is productive. I should have just looked
at the solution which is what I did at the end. I spent more time on this problem because I thought
that I was just about there to solving it. Next time I should set a hard time limit on the amount
of time to spend on a problem.

The solution involved sorting both vectors. Then add the elements of the passengers to a set.
If the capacity is full or the time is greater in the passengers element than the buses element
then move to the next buses element. The solution assigns the one before the passengers element
as the result. Final at the end if the buses still has capacity then it iterates from the bus 
element to any previous element to get a new result value.

The solution I looked at is from this link.
https://leetcode.com/problems/the-latest-time-to-catch-a-bus/discuss/2259176/Easy-C%2B%2B-Solution-Using-Queue-And-Set-or-optimised-without-queue

*/
