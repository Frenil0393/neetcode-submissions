class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* curr = st.top();
            if ((!curr->left && !curr->right) || (prev && (prev == curr->left || prev == curr->right))) {
                result.push_back(curr->val);
                st.pop();
                prev = curr;
            } else {
                if (curr->right) st.push(curr->right);
                if (curr->left) st.push(curr->left);
            }
        }
        
        return result;
    }
};
