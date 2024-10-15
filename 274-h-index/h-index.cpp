class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int maxi=0, n= citations.size();
        for(int i=0; i<n; i++){
            int h= n-i;
            if(citations[i]>=h) maxi= max(maxi, h);
        }
        return maxi;
    }
};