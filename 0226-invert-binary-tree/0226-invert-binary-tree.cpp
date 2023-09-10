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
    TreeNode* f(TreeNode* newroot){
        if(newroot==NULL) return NULL;
        if(newroot->left!=NULL) f(newroot->left);
        if(newroot->right!=NULL) f(newroot->right);
        
        TreeNode* l= newroot->left;
        TreeNode* r= newroot->right;
        newroot->left=r;
        newroot->right=l;
        return newroot;
     
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* newroot= root;
        TreeNode* final=f(newroot);
        return final;
    }
};