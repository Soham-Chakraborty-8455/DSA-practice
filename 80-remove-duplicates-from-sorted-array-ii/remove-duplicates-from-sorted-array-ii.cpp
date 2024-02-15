class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=-1, cnt=1;
        vector<int> arr;
        for(int i=0; i<nums.size(); i++){
            if(prev==nums[i]) cnt++;
            else{
                cnt=1;
                prev=nums[i];
            }
            if(cnt>2){
                continue;
            }
            arr.push_back(nums[i]);
        }
        int len= arr.size();
        for(int i=0; i<arr.size(); i++){
            nums[i]=arr[i];
        }
        return len;
    }
};