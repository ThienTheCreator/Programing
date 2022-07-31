/* 2358. Maximum Number of Groups Entering a Competition

You are given a positive integer array grades which represents the grades of students in a
university. You would like to enter all these students into a competition in ordered non-empty
groups, such that the ordering meets the following conditions:

The sum of the grades of students in the ith group is less than the sum of the grades of students
in the (i + 1)th group, for all groups (except the last).
The total number of students in the ith group is less than the total number of students in the
(i + 1)th group, for all groups (except the last).
Return the maximum number of groups that can be formed.

Example 1:

Input: grades = [10,6,12,7,3,5]
Output: 3
Explanation: The following is a possible way to form 3 groups of students:
- 1st group has the students with grades = [12]. Sum of grades: 12. Student count: 1
- 2nd group has the students with grades = [6,7]. Sum of grades: 6 + 7 = 13. Student count: 2
- 3rd group has the students with grades = [10,3,5]. Sum of grades: 10 + 3 + 5 = 18. 
Student count: 3
It can be shown that it is not possible to form more than 3 groups.

Example 2:

Input: grades = [8,8]
Output: 1
Explanation: We can only form 1 group, since forming 2 groups would lead to an equal number of
students in both groups.
 
Constraints:

1 <= grades.length <= 105
1 <= grades[i] <= 105

*/

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        
        int res = 0;
        int j = 0;
        int k = 1;
        int prevSum = 0;
        int curSum = 0;
        for(int i = 0; i < grades.size(); i++){
            curSum += grades[i];
            j++;
            if(curSum > prevSum && j >= k){
                k = j + 1;
                j = 0;
                prevSum = curSum;
                curSum = 0;
                res++;
            }
        }
        
        return res;
    }
};

/* Note

The solution sorts the array and forms the groups based on the sum and the number which form the
sum. Start at the begining with the smallest number, we keep track of the number used to sum and
the previous sum. When it previous sum is bigger and it is equal to or greater then the allow 
capacity increment result and change the capacity and previous sum then reset numbers of sum and
sum.

*/