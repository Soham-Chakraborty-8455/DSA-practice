class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff= INT_MAX, val= 1e5;
        for(int i=0; i<nums.size()-2; i++){
            int start= i+1, end= nums.size()-1;
            while(start<end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum==target) return sum;
                if(sum<target){
                    start++;
                } 
                if(sum>target){
                    end--;
                }
                int ele= abs(sum-target);
                if(ele<diff){
                    diff= ele;
                    // cout<<nums[i]<<" + "<< nums[start]<<" + "<<nums[end]<<" = "<<sum<< "gives diff "<<ele<<endl;  
                    val= sum;
                }
            }
        }
        return val;
    }
};