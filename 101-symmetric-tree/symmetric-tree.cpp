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
    bool check(TreeNode* p, TreeNode* q){
        if(p && !q) return false;
        if(q && !p) return false;
        if(!p && !q) return true;
        bool left= check(p->left, q->left);
        bool right= check(p->right , q->right);
        return (p->val==q->val) && left && right;
    }
    void f(TreeNode* root){
        if(root==NULL) return;
        TreeNode* l= root->left;
        TreeNode* r= root->right;
        root->left= r;
        root->right= l;
        f(root->left);
        f(root->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return false;
        f(root->left);
        return check(root->left, root->right);
    }
};