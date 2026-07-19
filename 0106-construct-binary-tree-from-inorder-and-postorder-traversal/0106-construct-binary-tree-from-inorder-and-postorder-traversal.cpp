class Solution {
    unordered_map<int, int> pos;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int left, int right) {
        if (left > right)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int mid = pos[root->val];

        root->right = build(postorder, mid + 1, right);
        root->left = build(postorder, left, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1);
    }
};