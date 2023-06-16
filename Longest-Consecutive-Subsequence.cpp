class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int counter=1;
        int maxi=1;
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        for(auto it: st){
            if(st.find(it-1)!=st.end()){
                counter++; 
                maxi=max(counter, maxi);
            }
            else{
                counter=1;
            }
        }
        return maxi;
    }
};
