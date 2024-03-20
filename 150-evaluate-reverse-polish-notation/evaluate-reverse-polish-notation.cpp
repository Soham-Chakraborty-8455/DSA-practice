class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto it: tokens){
            if(it=="+"){
                int ele= stoi(st.top());
                st.pop();
                int nextele= stoi(st.top());
                st.pop();
                st.push(to_string(ele+nextele));
            }
            else if(it=="-"){
                int ele= stoi(st.top());
                st.pop();
                int nextele= stoi(st.top());
                st.pop();
                st.push (to_string(nextele-ele));
            }
            else if(it=="*"){
                int ele= stoi(st.top());
                st.pop();
                int nextele= stoi(st.top());
                st.pop();
                st.push (to_string(nextele*ele));
            }
            else if(it=="/"){
                int ele= stoi(st.top());
                st.pop();
                int nextele= stoi(st.top());
                st.pop();
                st.push (to_string(nextele/ele));
            }
            else st.push(it);
        }
        return stoi(st.top());
    }
};