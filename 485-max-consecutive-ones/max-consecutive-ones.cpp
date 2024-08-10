class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int end=0, len=0, maxlen=0;
        while(end<nums.size()){
            if(nums[end]==1){
                len++;
                maxlen= max(maxlen, len);
            }
            else len=0;
            end++;
        }
        return maxlen;
    }
};