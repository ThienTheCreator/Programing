/* Convert Binary Number in a Linked List to Integer

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head != nullptr){
            res *= 2;
            res += head->val;
            head = head->next;
        }
        return res;
    }
};

/* Note

This solution is the most vote solution. I first had a solution where I stored the int values in 
a vector then calculated the decimal value. This solution has to do with bit shifting. 
Let's use the binary number 101 as the example: 

0 -> 0 + 1    = 0 * 2 + 1 = 1
1 -> 10 + 0   = 1 * 2 + 0 = 2
10 -> 100 + 1 = 2 * 2 + 1 = 5

We shift our answer one bit to the left which is equal to muliplying by 2. 

*/