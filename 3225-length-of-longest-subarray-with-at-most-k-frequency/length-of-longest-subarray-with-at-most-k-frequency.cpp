class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0, r=0, maxlen=0;
        map<int, int> mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                
                mp[nums[l]]--;
                l++;
            }
            maxlen= max(maxlen, r-l+1);
            
            r++;
        }
        return maxlen;
    }
};