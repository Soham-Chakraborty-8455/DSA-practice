class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> mp;
        vector<int> ans;
        for(auto it: nums){
            mp[it]++;
            if(mp[it]==2) ans.push_back(it);
        }
        return ans;
    }
};