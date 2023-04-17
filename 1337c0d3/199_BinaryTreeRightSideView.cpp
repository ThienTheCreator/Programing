/* 199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the
values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:

Input: root = [1,null,3]
Output: [1,3]

Example 3:

Input: root = []
Output: []
 
Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        vector<TreeNode*> levelNodes;
    
        if(root) {
            levelNodes.push_back(root);
        }

        while(levelNodes.size() > 0) {
            vec.push_back(levelNodes[levelNodes.size() - 1]->val);

            vector<TreeNode*> tempNodes;
            for(int i = 0; i < levelNodes.size(); i++) {
                if(levelNodes[i]->left){
                    tempNodes.push_back(levelNodes[i]->left);
                }

                if(levelNodes[i]->right) {
                    tempNodes.push_back(levelNodes[i]->right);
                }
            }

            levelNodes = tempNodes;
        }

        return vec;
    }
};

/* Note

Time: O(n)
Space: O(n)

The solution was easier to code and solve than balance tree. This problem require level order
traversal or breath first search then take the value of the last node in the level. 

*/