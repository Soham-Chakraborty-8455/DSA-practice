class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long n=nums.size(),mini=-1,maxi=-1,lastind=-1,ans=0;
        for(int i=0;i<n;++i){
            if(nums[i]<minK || nums[i]>maxK) lastind=i,mini=-1,maxi=-1;
            else{
                if(nums[i]==minK) mini=i;
                if(nums[i]==maxK) maxi=i;
                if(mini!=-1 && maxi!=-1) ans+=min(mini,maxi)-lastind;
            }
        }
        return ans;
    }
};