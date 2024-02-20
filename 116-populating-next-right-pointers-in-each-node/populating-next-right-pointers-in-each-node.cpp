class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) 
            return nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            Node* prev = nullptr;
            
            for (int i = 0; i < level_size; i++) {
                Node* current = q.front();
                q.pop();
                
                if (prev != nullptr) {
                    prev->next = current;
                }
                
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
                
                prev = current;
            }
            
            prev->next = nullptr;
        }
        
        return root;
    }
};
