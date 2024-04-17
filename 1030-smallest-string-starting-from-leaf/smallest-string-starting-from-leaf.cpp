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
    void f(TreeNode* root, vector<string>& arr, string output){
        if(root==NULL){
            return;
        }
        //node
        char ele= 'a'+root->val;
        output.push_back(ele);
        if(root->right==NULL && root->left==NULL){
            if(!output.empty()){ 
                reverse(output.begin(), output.end());
                arr.push_back(output);
            }
            return;
        }
        //left
        if(root->left)f(root->left, arr, output);
        //right
        if(root->right)f(root->right, arr, output);
        
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string> arr;
        string output="";
        f(root, arr, output);
        sort(arr.begin(), arr.end());
        return arr[0]; 
    }
};