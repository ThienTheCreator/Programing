/* 19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]
 
Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

Follow up: Could you do this in one pass?

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        int s = 0;
        ListNode* counter = head;
        
        while(counter != NULL){
            s++;
            counter = counter->next;
        }
        
        int count = s - n - 1;
        counter = head;
        while(count > 0){
            count--;
            counter = counter->next;
        }
        
        if(s - n <= 0){
            if(head->next == NULL){
                return NULL;
            }else{
                return head->next;
            }
        }
        
        counter->next = counter->next->next;
        return head;
    }
};

/* Note

The solution loops through the array once to get the size of the linked list. Then it calculates
the spot from the end based on the size. 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* slow = start;
        ListNode* fast = head;
        
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        
        return start->next;
    }
};

The solution above uses two pointers. the faster one is 1 + n from the slow pointer. It also
creates a node whose next value is the head. It is used to return the next val so it is easier to
get rid of the first node if it is choosen. 

*/