/* 110. Balanced Binary Tree

Given a binary tree, determine if it is 
height-balanced

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node
never differs by more than one.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true
 
Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104

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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }

    bool dfs(TreeNode* root, int& height) {
        if(root == NULL) {
            height = -1;
            return true;
        }

        int left = 0;
        int right = 0;

        if(!dfs(root->left, left) || !dfs(root->right, right)){
            return false;
        }

        if(abs(left - right) > 1){
            return false;
        }

        height = 1 + max(left, right);
        return true;
    }
};

/* Note

Time: O(n)
Space: O(n)

Wasn't able to solve problem. Stuck on how to implement solution. The first approach was closed to
the solution, but had difficulty figuring out method to use to solve problem. Started over a few
times.

*/