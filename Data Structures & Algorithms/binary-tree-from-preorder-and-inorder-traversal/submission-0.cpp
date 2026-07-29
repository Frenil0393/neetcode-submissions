class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        int preIndex = 0;
        return helper(preorder, inMap, preIndex, 0, inorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& preorder, unordered_map<int,int>& inMap, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inMap[rootVal];
        root->left = helper(preorder, inMap, preIndex, inStart, inIndex - 1);
        root->right = helper(preorder, inMap, preIndex, inIndex + 1, inEnd);
        return root;
    }
};
