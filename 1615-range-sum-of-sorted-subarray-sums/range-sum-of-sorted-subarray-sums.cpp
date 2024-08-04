class Solution {
private:
    // void f(int ind, vector<int>&nums, vector<int>&output, int sum){
    //     if(ind==nums.size()) return;
    //     //not-pick
    //     if(sum!=0) output.push_back(sum);
    //     f(ind+1, nums, output, sum);
    //     if(sum!=0) output.pop_back();
    //     //pick
    //     sum+=nums[ind];
    //     f(ind+1, nums, output, sum);
    // }
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int modulo= 1e9+7;
        vector<long long> output;
        // f(0, nums, output, 0);
        for(int i=0; i<nums.size(); i++){
            long long sum=0;
            for(int j=i; j<nums.size(); j++){
                sum+=nums[j];
                output.push_back(sum);
            }
        }
        sort(output.begin(), output.end());
        // for(auto it: output){
        //     cout<<it<<" ";
        // }
        long long ans=0;
        for(int i=left-1; i<right; i++){
            ans+=output[i];
        }
        int finall= ans%modulo;
        return finall;
    }
};