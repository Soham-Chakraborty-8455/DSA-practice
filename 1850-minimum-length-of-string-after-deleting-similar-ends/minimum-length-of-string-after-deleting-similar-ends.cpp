class Solution {
public:
    int minimumLength(string s) {
        deque<char> dq;
        for(auto it: s){
            dq.push_back(it);
        }
        char prev;
        while(dq.size()>=2){
            int front= dq.front();
            int rare= dq.back();
            if(front==rare){
                dq.pop_front();
                dq.pop_back();
                prev= front;
            }
            else if(prev==rare){
                dq.pop_back();
            }
            else if(front== prev){
                dq.pop_front();
            }
            else break;
        }
        if(dq.size()==1 && dq.front()==prev) return 0;
        return dq.size();
    }
};