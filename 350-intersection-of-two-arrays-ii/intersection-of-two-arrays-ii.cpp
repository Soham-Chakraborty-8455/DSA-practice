class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp1, mp2;
        for(auto it: nums1){
            mp1[it]++;
        }
        for(auto it: nums2){
            mp2[it]++;
        }
        for(auto it:mp1){
            if(mp2[it.first]){
                int mini=min(mp2[it.first], mp1[it.first]);
                while(mini--){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};