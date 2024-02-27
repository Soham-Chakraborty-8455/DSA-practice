class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char, int> mp;
        map<char, int> occ;
        for(int i=0; i<s.length(); i++){
            occ[s[i]]=i;
        }
        for(auto it: s){
            mp[it]++;
        }
        int maxi= -1;
        for(auto it: mp){
            maxi= max(maxi, it.second);
        }
        string str="";
        for(auto it: mp){
            if(it.second==maxi){
                str.push_back(it.first);
            }
        }
        vector<pair<int, char>> p;
        for(auto it: str){
            p.push_back({occ[it], it});
        }
        sort(p.begin(), p.end());
        string ans="";
        for(auto it: p) ans.push_back(it.second);
        return ans;
    }
};