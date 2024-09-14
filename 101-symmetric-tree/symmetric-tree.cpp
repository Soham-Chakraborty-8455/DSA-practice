class Solution {
private:
    bool check(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true; 
        if (p == nullptr || q == nullptr) return false;
        return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true; 
        return check(root->left, root->right);
    }
};
