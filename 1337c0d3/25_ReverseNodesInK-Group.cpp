/* 25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified
list.

k is a positive integer and is less than or equal to the length of the linked list. If the number
of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed. 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 
Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 
Follow-up: Can you solve the problem in O(1) extra memory space?

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        ListNode* temp = NULL;

        int count = 0;
        while(curr){
            if(count < k - 1){
                temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                count++;
            }else{
                prev = curr;
                curr=curr->next;
                count = 0;

                ListNode* end = curr;
                for(int i = 0; i < k; i++){
                    if(end == NULL){
                        return dummy->next;
                    }
                    end = end->next;
                }
            }
        }
        
        return dummy->next;
    }
};

/* Note

Time: O(n) where n is the number of nodes
Space: O(1)

I wasn't able to solve this problem. Look up the answer but also spent some time drawing out what
the pointers where doing. I was confuse about the problem so I think I should reread the prompt and
try so test cases before starting.

Keep track of three pointers. It is guarantee that the at least one k reverse happening in the
linked list. The prev keep track of the begining. The curr keeps track of the front of the list.
The temp is temporary to swap items in the list. When it hits k elements we check if the next k
items if it is possible to continue.

*/