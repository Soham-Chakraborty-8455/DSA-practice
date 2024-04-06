class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        map<int, int> erasing;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push({s[i], i});
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    erasing[i]++;
                }
            }
        }
        while(!st.empty()){
            erasing[st.top().second]++;
            st.pop();
        }
        string str="";
        for(int i=0; i<s.length(); i++){
            if(erasing.find(i)==erasing.end()){
                str.push_back(s[i]);
            }
        }
        return str;
    }
};