/* 897. Increasing Order Search Tree

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in
the tree is now the root of the tree, and every node has no left child and only one right child.

Example 1:

Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

Example 2:

Input: root = [5,1,7]
Output: [1,null,5,null,7]
 
Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000

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
    TreeNode* temp;
    TreeNode* res;
    TreeNode* increasingBST(TreeNode* root) {
        
        if(root == nullptr){
            return NULL;
        }
        
        increasingBST(root->left);
        
        if(res == nullptr){
            res = new TreeNode(root->val);
            temp = res;
        }else{
            temp->right = new TreeNode(root->val);
            temp = temp->right;
        }
        
        increasingBST(root->right);
        
        return res;
    }
};

/* Note

I looked at lee215 solution from
https://leetcode.com/problems/increasing-order-search-tree/discuss/165885/C%2B%2BJavaPython-Self-Explained-5-line-O(N)

The solution is interesting because it had the line:
TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL)

It passed in a variable that can be use without an argument needing to be passed in. 

*/