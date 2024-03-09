class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for(auto it: nums1){
            mp[it]++;
        }
        for(auto it: nums2){
            if(mp.find(it)!= mp.end()){
                return it;
            }
        }
        return -1;
    }
};