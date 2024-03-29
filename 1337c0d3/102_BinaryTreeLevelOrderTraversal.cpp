/* 102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).
 
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
 
Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        
        if(root != NULL)
            q.push(root);
        
        while(q.size()){
            int count = q.size();
            vector<int> temp(count);
            for(int i = 0; i < count; i++){
                temp[i] = q.front()->val;
                
                if(q.front()->left)
                    q.push(q.front()->left);
                    
                if(q.front()->right)
                    q.push(q.front()->right);
                
                q.pop();
            }
            res.push_back(temp);
        }
        
        return res;
    }
};

/* Note

To have inorder traversal, I used a queue to store the level and the next level. 

*/