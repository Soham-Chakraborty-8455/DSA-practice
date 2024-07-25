class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        sort(nums.begin(), nums.end());
        int maxi=1, cnt=1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]==nums[i]) continue;
            else if(nums[i+1]-nums[i]==1){
                cnt++;
                maxi= max(maxi, cnt);
            }
            else{
                cnt=1;
            }
        }
        return maxi;
    }
};