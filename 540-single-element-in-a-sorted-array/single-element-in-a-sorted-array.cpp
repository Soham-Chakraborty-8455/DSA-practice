class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low= 0, high= nums.size()-1;
        if(nums[low]!=nums[low+1]) return nums[low];
        if(nums[high]!=nums[high-1]) return nums[high];
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(nums[mid]!= nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            if(mid%2==0 && nums[mid+1]==nums[mid] || mid%2==1 && nums[mid-1]==nums[mid]) low=mid+1;
            if(mid%2==0 && nums[mid-1]==nums[mid] || mid%2==1 && nums[mid+1]==nums[mid]) high=mid-1;

        }
        return -1;
    }
};