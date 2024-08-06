class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start=0;
        for(int end=1; end<nums.size(); end++){
            if(nums[start]!=nums[end]){
                start++;
                nums[start]=nums[end];
            }
        }
        return start+1;
    }
};