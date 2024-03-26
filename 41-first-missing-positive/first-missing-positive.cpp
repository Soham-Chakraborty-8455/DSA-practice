class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> sol(nums.size()+2,0);
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0 && nums[i]<=nums.size())
                sol[nums[i]]=1;
        }
        for(int i=1;i<sol.size();i++)
        {
            if(sol[i]==0)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};