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
    void inorder(TreeNode* root, map<int, int>& mp){
        if(root==NULL ) return;
        inorder(root->left, mp);
        mp[root->val]++;
        inorder(root->right, mp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        map<int, int> mp;
        inorder(root, mp);
        int maxi=0;
        vector<int> ans;
        for(auto it: mp){
            maxi=max(maxi, it.second);
        }
        for(auto it: mp){
            if(it.second==maxi) ans.push_back(it.first);
        }
        return ans;
    }
};