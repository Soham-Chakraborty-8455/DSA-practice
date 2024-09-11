class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>> pq;
        int low=0, high=0, freq=0;
        while(high<nums.size()){
            if(nums[high]==nums[low]){
                freq++;
            }
            else{
                pq.push({freq, nums[low]});
                low= high;
                freq=1;
            }
            high++;
        }
        pq.push({freq, nums[low]});
        vector<int> ans;
        for(int i=0; i<k; i++){
            int ele= pq.top().second;
            pq.pop();
            ans.push_back(ele);
        }
        return ans;
    }
};