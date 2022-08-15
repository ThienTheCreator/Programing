/* 105. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary
tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, preorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIndex, int left, int right){
        if(left > right)
            return NULL;
        
        TreeNode* newNode = new TreeNode(preorder[rootIndex]);
        int pivot = left;
        
        while(inorder[pivot] != preorder[rootIndex]) 
            pivot++;
        
        rootIndex++;
        newNode->left = build(preorder, inorder, rootIndex, left, pivot - 1);
        newNode->right = build(preorder, inorder, rootIndex, pivot + 1, right);
        
        return newNode;
    }
};

/* Note

Wasn't able to solve this question in 30 minutes. To solve the question, it need you to know about
the property of preorder and inorder traversal. You need to find the a pivot based on preorder to
split the inorder value to recursed.

Another solution using hash map I found.

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map; int preIdx = 0;

        for (int i = 0; i < size(inorder); i++) map[inorder[i]] = i;

        function<TreeNode*(int, int)> traverse = [&](int left, int right) -> TreeNode* {

            if (left > right) return NULL;

            auto root = preorder[preIdx++];

            return new TreeNode(root, traverse(left, map[root] - 1), traverse(map[root] + 1, right));

        };

        return traverse(0, size(preorder) - 1);
        
    }
};

The hashmap is used to map the inorder values to an index.

*/