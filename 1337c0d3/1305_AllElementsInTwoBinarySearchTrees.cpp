/* 1305. All Elements in Two Binary Search Trees

Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        addToVector(root1, res);
        addToVector(root2, res);
        sort(res.begin(), res.end());
             
        return res;
    }
    
    void addToVector(TreeNode *root, vector<int> &temp){
        if(root == NULL){
            return;
        }
        
        temp.push_back(root->val);
        addToVector(root->left, temp);
        addToVector(root->right, temp);
    }
};

/* Note

My solution just add both to a vector then sort the vector at the end. I did not realize that the
trees were already sorted since they are binary search tree. The most voted I saw was from votrubac
The solution iterated through using inorder traversal and combine the the smallest of the two
values.

*/