class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        int maxi=-1;
        for(auto it: mp){
            // cout<<it.first<<" : "<<it.second<<endl;
            maxi= max(maxi, it.second);
        }
        // cout<<maxi<<endl;
        int ans=0;
        for(auto it: mp){
            if(it.second==maxi){
                ans+=it.second;
            }
        }
        return ans;
    }
};