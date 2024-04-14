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
private:
    int f(TreeNode* root, bool isleft) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            if (isleft) {
                return root->val;
            } else {
                return 0;
            }
        }
        return f(root->left, true) + f(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return f(root, false);
    }
};