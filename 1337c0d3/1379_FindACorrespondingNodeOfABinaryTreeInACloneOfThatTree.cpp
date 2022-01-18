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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(cloned);
        TreeNode* temp;
        while(q.size()){
            temp = q.front();
            if(temp->val == target->val){
                return temp;
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
            q.pop();
        }
        return temp;
    }
};

/* Note

I used an iterative way because I tried implementing a recursive way, but 
found that writing the code iterative was easier. 

*/