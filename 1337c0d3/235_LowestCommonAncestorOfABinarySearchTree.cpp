/* 235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in
the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two
nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node
to be a descendant of itself).”

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
 
Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
            
        return root;
    }
};

/* Note

My solution was more complicated then it need to be.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool hasP = false, hasQ = false;
        
        if(isAncestor(root->left,p,q,hasP,hasQ))
            return lowestCommonAncestor(root->left, p, q);
        
        hasP = 0;
        hasQ = 0;
        
        if(isAncestor(root->right,p,q,hasP,hasQ))
            return lowestCommonAncestor(root->right, p, q);
            
        return root;
    }
    
    bool isAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool &hasP, bool &hasQ){
        if(root == NULL)
            return false;
        
        if(root->val == p->val)
            hasP = true;
        
        if(root->val == q->val)
            hasQ = true;
        
        if(hasP && hasQ){
            return true;
        }
        
        return isAncestor(root->left, p, q, hasP, hasQ) || isAncestor(root->right, p, q, hasP, hasQ);
    }
};

I did not realize that the tree was a Binary Search Tree. My answer assume that it was not a binary
search tree so that is why I check if the both have a ancestor.

The solution given that the tree is a bst is to check if both values are greater than root val or 
check if both values are less then the root value. If the root is in between p and q values, then
we know that we can return it because bst is sorted where smaller values are on the left, and
larger values are on the right. Also all the node are unique.

*/