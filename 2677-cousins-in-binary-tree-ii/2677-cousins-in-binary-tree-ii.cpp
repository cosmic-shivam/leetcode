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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;
    
    // Level order traversal (BFS)
    std::queue<TreeNode*> q;
    q.push(root);
    
    root->val = 0;  // Set the root value to 0, as it has no cousins.
    
    while (!q.empty()) {
        int size = q.size();
        int level_sum = 0;  // Sum of all nodes at the current level.
        std::vector<TreeNode*> nodes;  // Store nodes at the current level.
        
        // Calculate the total sum of the current level
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            nodes.push_back(node);  // Collect nodes at the current level
            if (node->left) {
                level_sum += node->left->val;
                q.push(node->left);
            }
            if (node->right) {
                level_sum += node->right->val;
                q.push(node->right);
            }
        }
        
        // Now assign the sum of cousins for each node at this level
        for (TreeNode* node : nodes) {
            int sibling_sum = 0;  // Sum of the node's sibling (if it has one)
            
            if (node->left && node->right) {
                sibling_sum = node->left->val + node->right->val;  // Siblings
                node->left->val = level_sum - sibling_sum;  // Assign cousin sum for left child
                node->right->val = level_sum - sibling_sum;  // Assign cousin sum for right child
            } else if (node->left) {
                node->left->val = level_sum - node->left->val;  // No sibling, assign cousin sum
            } else if (node->right) {
                node->right->val = level_sum - node->right->val;  // No sibling, assign cousin sum
            }
        }
    }
    
    return root;
        
    }
};