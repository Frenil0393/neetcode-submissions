class Solution {
public:
    unordered_map<TreeNode*, int> memo;
    
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (memo.count(root)) return memo[root];
        
        int robRoot = root->val;
        if (root->left) robRoot += rob(root->left->left) + rob(root->left->right);
        if (root->right) robRoot += rob(root->right->left) + rob(root->right->right);
        
        int skipRoot = rob(root->left) + rob(root->right);
        
        return memo[root] = max(robRoot, skipRoot);
    }
};
