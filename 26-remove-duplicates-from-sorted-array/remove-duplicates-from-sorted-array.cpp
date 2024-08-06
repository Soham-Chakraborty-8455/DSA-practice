class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        int ind=0;
        for(auto& it: st){
            nums[ind]= it;
            ind++;
        }
        return st.size();
    }
};