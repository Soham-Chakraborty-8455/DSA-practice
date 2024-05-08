class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<score.size(); i++){
            pq.push({score[i], i});
        }
        vector<string> ans(score.size(), "");
        int cnt=1;
        while(!pq.empty()){
            int ind= pq.top().second;
            pq.pop();
            if(cnt==1){
                ans[ind]= "Gold Medal";
            }
            else if(cnt==2){
                ans[ind]= "Silver Medal";
            }
            else if(cnt==3){
                ans[ind]= "Bronze Medal";
            }
            else{
                ans[ind]= to_string(cnt);
            }
            cnt++;
        }
        return ans;
    }
};