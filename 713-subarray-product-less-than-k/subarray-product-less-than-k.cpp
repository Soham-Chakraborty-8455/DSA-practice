class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int l=0, r=0, prod=1, n=0;
        while(r<nums.size()){
            prod= prod* nums[r];
            while(prod>=k){
                prod= prod/nums[l];
                l++;
            }
            if(prod<k){
                n+= r-l+1;
            }
            r++;
        }
        return n;
    }
};