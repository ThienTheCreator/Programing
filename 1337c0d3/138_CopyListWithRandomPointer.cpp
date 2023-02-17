/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> um;
        Node* tempHead = head;

        while(tempHead){
            um[tempHead] = new Node(tempHead->val);
            tempHead = tempHead->next;
        }

        tempHead = head;
        while(tempHead){
            um[tempHead]->next = um[tempHead->next];
            um[tempHead]->random = um[tempHead->random];
            tempHead = tempHead->next;
        }

        return um[head];
    }
};

/* Note

Couldn't solve this one. Didn't know pointers are like addresses. 

Time: O(n)
Space: O(n)

The solution stores the pointer into a hashmap. Then it traverses through the nodes and saves a new
node with the same value in the hashmap. After it traverses the head node again and sets the next
and random nodes based on the value store in the hashmap corresponding to the original pointer.

*/