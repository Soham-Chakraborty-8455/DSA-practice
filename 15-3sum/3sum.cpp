class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n= nums.size();
        for(int i=0; i<n; i++){
            int j=i+1, k= n-1;
            while(j<k){
                // cout<<i<<j<<k<<endl;
                int sum= nums[i] + nums[j] + nums[k];
                if(sum==0){
                    if(st.find({nums[i], nums[j], nums[k]})== st.end()){
                        st.insert({nums[i], nums[j], nums[k]});
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                    j++;
                    k--;
                }
                if(sum<0) j++;
                if(sum>0) k--;
            }
        }
        return ans;
    }
};