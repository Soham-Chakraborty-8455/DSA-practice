class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start=0, end= 0, curr=0, maxi=INT_MIN;
        while(end<t.length()){
            curr= curr+ abs(int(s[end])-int(t[end]));
            while(curr>maxCost){
                curr = curr- abs(int(s[start])-int(t[start]));
                start++;
            }
            maxi=max(maxi, end-start+1);
            end++;
        }
        return maxi;
    }
};