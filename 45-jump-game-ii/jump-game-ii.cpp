class Solution {
private:
    int f(int ind, vector<int>&nums, vector<int>&dp){
        if(ind== nums.size()-1) return 0;
        if(ind>=nums.size()) return 1e8;
        if(nums[ind]==0) return 1e8;
        if(dp[ind]!=-1) return dp[ind];
        int jump= INT_MAX;
        for(int i=1; i<=nums[ind]; i++){
            int chalang= INT_MAX;
            if(ind+i <nums.size()) chalang= 1 + f(ind+i, nums, dp);
            jump = min(jump, chalang);
        }
        return dp[ind]= jump;
    }
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int> dp (nums.size()+1, -1);
        return f(0, nums, dp);
    }
};