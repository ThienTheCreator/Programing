/* 21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of
the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 
Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        ListNode* smallest;
        
        if(list1 == nullptr && list2 != nullptr){
            return list2;
        }
        
        if(list1 != nullptr && list2 == nullptr){
            return list1;
        }
        
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val > list2->val){
                smallest = list2;
                list2 = list2->next;
            }else{
                smallest = list1;
                list1 = list1->next;
            }
            
            if(head == nullptr){
                head = smallest;
                tail = head;
            }else{
                tail->next = smallest;
                tail = tail->next;
            }
        }
        
        while(list1 != nullptr){
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
        
        while(list2 != nullptr){
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
        
        return head;
    }
};

/* Note

My solution used three nodes to keep track of the linked lists. When the two lists are not nullptr
we compare the val for the two. Add the smallest value node as the next node for the tail.

https://leetcode.com/problems/merge-two-sorted-lists/discuss/9714/14-line-clean-C%2B%2B-Solution
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

The solution I had a more lines of code. The solution above shows some ways to condense the logic
into fewer lines of code. I could have use two nodes instead of three. Created a node and giving it
a value would remove the need for the if condition in my solution. 

*/