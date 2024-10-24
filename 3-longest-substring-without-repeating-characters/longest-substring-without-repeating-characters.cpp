class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int start=0, end=0, maxi= 0;
        while(end<s.length()){
            mp[s[end]]++;
            while(mp[s[end]]>1){
                mp[s[start]]--;
                start++;
            }
            maxi= max(maxi, end-start+1);
            end++;
        }
        return maxi;
    }
};