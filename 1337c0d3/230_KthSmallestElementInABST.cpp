/* 230. Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed)
of all the values of the nodes in the tree.

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 
Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 
Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need
to find the kth smallest frequently, how would you optimize?

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }
    
    int helper(TreeNode* root, int &k){
        int temp;
        if(root->left)
            temp = helper(root->left, k);
            
        if(temp != -1)
            return temp;
        
        k--;
        if(k == 0){
            return root->val;
        }
        
        if(root->right)
            temp = helper(root->right, k);
        
        if(temp != -1)
            return temp;
        
        return -1;
    }
};

/* Note

The solution is 
Time: O(n) 
Space: O(n)     Think about a tree with only left node. The space would be the height of the tree.

The solution below is from neetcode

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        inorder(root, k, result);
        return result;
    }
private:
    void inorder(TreeNode* root, int& k, int& result) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, k, result);
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }
};

It uses int result which simplified the code a bit.

The solution below is iterative using a stack.

class Solution {
public:
    int kthSmallest(TreeNode* node, int k) {
        stack<TreeNode*>st;
        while (node || !st.empty()) {
            while (node!=0) {
                st.push(node);
                node=node->left;
            }
            
            node = st.top();
            st.pop();
            
            if (--k == 0) 
                return node->val;
            node = node->right;
        }
        return -1;
    }
};

This solution is interesting to me because I was trying to figure out an iterative way of inorder
traversal and what I thought of was different from this.

*/