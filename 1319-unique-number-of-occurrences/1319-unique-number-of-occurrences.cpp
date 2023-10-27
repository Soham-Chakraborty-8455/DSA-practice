class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        vector<int> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size()-1; i++){
            if(ans[i]==ans[i+1]) return false;
        }
        return true;
    }
};