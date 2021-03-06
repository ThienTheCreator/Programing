/* 1302. Deepest Leaves Sum

Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100

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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> tempQueue;
        TreeNode * tempRoot;
        tempQueue.push(root);
        int res;
        while(!tempQueue.empty()){
            int s = tempQueue.size();
            res = 0;
            for(int i = 0; i < s; i++){
                tempRoot = tempQueue.front();
                if(tempRoot->left != NULL){
                    tempQueue.push(tempRoot->left);
                }
                if(tempRoot->right != NULL){
                    tempQueue.push(tempRoot->right);
                }
                res += tempRoot->val;
                tempQueue.pop();
            }
        }
        
        return res;
    }
};

/* Note

Fot this problem, a queue is use to loop through the levels. After each level
we reset the answer to 0. We accumulate the the values at each level. 
To look at the elements of the queue we front().

*/