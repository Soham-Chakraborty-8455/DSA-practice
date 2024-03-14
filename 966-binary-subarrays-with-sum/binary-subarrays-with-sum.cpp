class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefixsum=0; 
        int cnt=0;
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            prefixsum+=nums[i];
            if(prefixsum==goal){
                cnt++;
            }
            if(mp.find(prefixsum-goal)!=mp.end()){
                cnt+=mp[prefixsum-goal];
            }
            mp[prefixsum]++;
        }
        return cnt;
    }
};