class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start=0;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(ans[start][1]>=intervals[i][0]){
                ans[start][1]= max(intervals[i][1], ans[start][1]); 
            }
            else{
                ans.push_back(intervals[i]);
                start++;
            }
        }
        return ans;

    }
};