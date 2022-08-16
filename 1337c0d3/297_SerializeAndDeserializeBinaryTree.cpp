/* 297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so
that it can be stored in a file or memory buffer, or transmitted across a network connection link
to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can
be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do
not necessarily need to follow this format, so please be creative and come up with different
approaches yourself.

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []
 
Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }
    
    void encode(TreeNode* root, ostringstream &out){
        if(root == NULL){
            out << "N ";
        }else{
            out << root->val << " ";
            encode(root->left, out);
            encode(root->right, out);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
    
    TreeNode* decode(istringstream &in){
        string s;
        in >> s;
        if(s == "N"){
            return NULL;
        }
        
        int i = stoi(s);
        TreeNode* temp = new TreeNode(i);
        temp->left = decode(in);
        temp->right = decode(in);
        
        return temp;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

/* Note

Was not able to solve this one in 20 minutes. Tried to convert to an array like string that would
have level order traversal. The solution used preorder traversal to encode and decode. Did not know
about or remember ostringstream and istringstream.

Time: O(n)
Space O(n)

*/