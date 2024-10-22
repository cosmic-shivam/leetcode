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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1; // If the tree is empty
    
    queue<TreeNode*> q;
    q.push(root);
    
    vector<long long> levelSums; // To store sums of each level
    
    // BFS to traverse the tree level by level
    while (!q.empty()) {
        int levelSize = q.size();
        long long levelSum = 0;
        
        // Process each node at this level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            // Add the node's value to the level sum
            levelSum += node->val;
            
            // Add its children to the queue for the next level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        // Store the sum of the current level
        levelSums.push_back(levelSum);
    }
    
    // If there are fewer than k levels, return -1
    if (levelSums.size() < k) return -1;
    
    // Sort the level sums in descending order to find the k-th largest sum
    sort(levelSums.rbegin(), levelSums.rend());
    
    // Return the k-th largest level sum
    return levelSums[k-1];
    }
};