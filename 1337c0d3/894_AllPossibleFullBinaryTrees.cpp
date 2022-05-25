/* 894. All Possible Full Binary Trees

Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each
tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of
trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Example 1:

Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],
    [0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

Example 2:

Input: n = 3
Output: [[0,0,0]]
 
Constraints:

1 <= n <= 20

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
    map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(memo.find(n) == memo.end()){
            vector<TreeNode*> ans;
            if(n == 1){
                ans.emplace_back(new TreeNode(0));
            }else if(n % 2){
                for(int i = 0; i < n; ++i){
                    int j = n - 1 - i;
                    for(TreeNode* left: allPossibleFBT(i)){
                        for(TreeNode* right: allPossibleFBT(j)){
                            TreeNode* bns = new TreeNode(0);
                            bns->left = left;
                            bns->right = right;
                            ans.emplace_back(clone(bns));
                        }
                    }
                }
            }
            memo[n] = ans;
        }    
        
        return memo[n];
    }
};

/* Note

This solution took me a while to understand. I first thought of building a tree then iterating on
throught the leafs of the tree to create a new tree. The solution is given in the problem and I
just converted form Java to C++. 

I was also looking at the most voted solution by ChrisTrompf.
https://leetcode.com/problems/all-possible-full-binary-trees/discuss/167402/c%2B%2B-c-java-and-python-recursive-and-iterative-solutions.-Doesn't-create-Frankenstein-trees

The solution has a recursive solution as well as an iterative solution using cache to build the
tree. Something to keep in mind is building from bottom up or top down.

*/