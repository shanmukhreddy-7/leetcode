class Solution {
    ListNode* head;

    TreeNode* build(int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* leftChild = build(left, mid - 1);

        TreeNode* root = new TreeNode(head->val);
        head = head->next;

        root->left = leftChild;
        root->right = build(mid + 1, right);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;

        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        return build(0, n - 1);
    }
};