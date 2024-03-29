/* 143. Reorder List

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 
Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000

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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast=fast->next->next;
        }
        
        fast = slow;
        fast = fast->next;
        slow->next = NULL;
        
        stack<ListNode*> s;
        while(fast != NULL){
            s.push(fast);
            fast = fast->next;
        }
        
        ListNode* nextNode = NULL;
        while(!s.empty()){
            nextNode = head->next;
            head->next = s.top();
            s.pop();
            head = head->next;
            head->next = nextNode;
            head = head->next;
        }
    }
};

/* Note

The solution uses two pointer to find the middle of the linked list. Then add the second half of
the list into a stack. Then reorder the list based on the linked list and the stack.

The fastest solution which ran is below.

class Solution {
public:
    ListNode* reverse(ListNode *head){
        ListNode *prev=NULL;
        ListNode *nxt;
        ListNode *curr=head;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next = prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *first=head;
        ListNode *second = reverse(slow->next);
        slow->next=NULL;
        while(second){
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};

*/