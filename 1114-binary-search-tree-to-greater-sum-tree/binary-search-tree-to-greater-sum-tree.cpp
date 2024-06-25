class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);
        reverse(inorderTraversal.begin(), inorderTraversal.end());
        replaceValues(root, inorderTraversal);

        return root;
    }

private:
    void inorder(TreeNode* root, vector<int>& inorderTraversal) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, inorderTraversal);
        inorderTraversal.push_back(root->val);
        inorder(root->right, inorderTraversal);
    }
    void replaceValues(TreeNode* root, vector<int>& inorderTraversal) {
        if (root == nullptr) {
            return;
        }
        replaceValues(root->left, inorderTraversal);
        replaceValues(root->right, inorderTraversal);

        int nodeSum = 0;
        for (auto i : inorderTraversal) {
            if (i > root->val) {
                nodeSum += i;
            } else {
                break;
            }
        }

        root->val += nodeSum;
    }
};