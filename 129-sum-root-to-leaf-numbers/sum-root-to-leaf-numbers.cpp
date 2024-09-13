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
    void f(TreeNode* root, int num, vector<int>& paths){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            num= 10*num + root->val;
            paths.push_back(num);
            return;
        }
        num= 10*num + root->val;
        f(root->left, num, paths);
        f(root->right, num, paths);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> paths;
        f(root, 0, paths);
        int ans=0;
        for(auto it: paths) ans+= it;
        return ans;
    }
};