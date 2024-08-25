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
 //copied
class Solution {
public:
   void postorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    
    // Traverse left subtree
    postorder(root->left, result);
    
    // Traverse right subtree
    postorder(root->right, result);
    
    // Visit the root node
    result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    postorder(root, result);
    return result;
}

};