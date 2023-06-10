class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n=arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second>n/3) ans.push_back(it.first);
        }
        return ans;
    }
};
