class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start= 0, end= nums.size()-1;
        while(start<end){
            if(nums[start]+nums[end]==0) return nums[end];
            if(nums[start]+nums[end]<0) start++;
            if(nums[start]+nums[end]>0) end--;
        }
        return -1;
    }
};