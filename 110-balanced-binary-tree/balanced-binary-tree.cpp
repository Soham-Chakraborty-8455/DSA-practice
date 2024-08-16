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
    int height(TreeNode* root, bool& balanced){
        if(root==NULL) {
            balanced = balanced &&true;
            return 0;
        }
        int l= height(root->left, balanced);
        int r= height(root->right, balanced);
        int diff= l-r;
        if(diff==-1 || diff==0 || diff==1) balanced= balanced && true;
        else balanced= balanced && false;
        return max(l, r)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        bool balanced= true;
        int h= height(root, balanced);
        return balanced;
    }
};