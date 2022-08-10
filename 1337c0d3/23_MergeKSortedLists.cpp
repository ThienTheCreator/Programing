/* 23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: [] 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* start = new ListNode(INT_MIN);
        for(int i = 0; i < lists.size(); i++){
            mergeLists(start, lists[i]);
        }
        return start->next;
    }
    
    void mergeLists(ListNode* list1, ListNode* list2){
        ListNode* prev = list1;
        while(list1 && list2){
            if(list1->val < list2->val){
                prev = list1;
                list1 = list1->next;
            }else{
                prev->next = list2;
                list2 = list2->next;
                prev = prev->next;
                prev->next = list1;
            }
        }
        
        if(list1 == NULL){
            prev->next = list2;
        }
    }
};

/* Note

The solution uses the merge two list together to merge one list with all the other lists.

I also optimize my code to run faster below based on solution from neetcode:
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        if(n == 0){
            return NULL;
        }
        
        while(n > 1){
            for(int i = 0; i < n/2; i++){
                lists[i] = mergeLists(lists[i], lists[n-i-1]);
            }
            n = (n + 1)/2;
        }
        
        return lists[0];
    }
    
    ListNode* mergeLists(ListNode* list1, ListNode* list2){
        ListNode* head = new ListNode(INT_MIN);
        ListNode* tail = head;
        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }else{
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        
        tail->next = list1 ? list1 : list2;
        
        return head->next;
    }
};

*/