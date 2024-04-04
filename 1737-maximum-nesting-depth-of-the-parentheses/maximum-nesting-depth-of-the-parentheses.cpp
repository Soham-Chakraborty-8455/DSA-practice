class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi=0;
        for(auto it: s){
            if(it=='('){
                st.push(it);
                int len= st.size();
                maxi= max(maxi, len);
            }
            if(it==')'){
                st.pop();
            }
            
        }
        return maxi;
    }
};