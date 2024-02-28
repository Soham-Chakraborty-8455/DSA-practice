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
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> arr;
        q.push(root);
        while(!q.empty()){
            int sz= q.size();
             vector<int> v;
            for(int i=0; i<sz; i++){
                TreeNode * node= q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            arr.push_back(v);
            
        }
        int size= arr.size();
            return arr[size-1][0];
    }
};