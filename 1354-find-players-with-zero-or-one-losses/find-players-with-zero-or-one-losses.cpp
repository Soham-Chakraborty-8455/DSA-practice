class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> win, loose;
        for(int i=0; i<matches.size(); i++){
            win[matches[i][0]]++;
            loose[matches[i][1]]++;
        }
        // vector<vector<int>> ans;
        vector<int> winners, loosers;
        for(auto it: win){
            if(loose.find(it.first)==loose.end()){
                winners.push_back(it.first);
            }
        }
        // sort(winners.begin(), winners.end());
        for(auto it: loose){
            if(it.second==1){
                loosers.push_back(it.first);
            }
        }
        return {winners, loosers};
    }
};