/* 1448. Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path from root to X there
are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

Example 1:

Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2:

Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 
Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].

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
    int goodNodes(TreeNode* root) {
        int value = root->val;
        int result = 0;
        int maximum = root->val;

        dfs(root, maximum, result);

        return result;
    }

    void dfs(TreeNode* root, int maximum, int &result){
        if(root->val >= maximum)
            result++;
        maximum = max(maximum, root->val);

        if(root->left)
            dfs(root->left, maximum, result);

        if(root->right)
            dfs(root->right, maximum, result);
    }
};

/* Note

Time: O(n)
Space: O(n)

I actually misunderstood the question so I had to do a fresh restart in the middle. I breifly
glanced over the question and example. Next time spend more time reading the question and looking
at the example. The solution is doing a dfs going left and right keeping track of the maximum value
encountered. If the max value is less than or equal to the current node value then increment the
counter.

*/