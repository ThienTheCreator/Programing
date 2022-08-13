/* 98. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:

Input: root = [2,1,3]
Output: true
Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

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
    bool isValidBST(TreeNode* root) {        
        TreeNode* prev = NULL;
        return checkBST(root, prev);
    }
    
    bool checkBST(TreeNode* root, TreeNode* &prev){
        bool l = true, r = true;
        if(root->left){
            l = checkBST(root->left, prev);
        }
        
        if(prev && prev->val >= root->val)
            return false;
        prev = root;

        if(root->right){
            r = checkBST(root->right, prev);
        }
        
        return l && r;
    }
};

/* Note 

Was stuck on this problem for a while. Try creating a minimum and maximum int to pass to a function
to compare values but when the values are at the largest or smallest number it messed up the
function. 

The solution to this problem was inorder traversal and using a pointer to the previous one to keep
track and compare to the current iteration.

*/