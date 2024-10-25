class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp1, mp2;
        for(auto it: ransomNote) mp1[it]++;
        for(auto it: magazine) mp2[it]++;
        for(auto it: mp1){
            if(mp2.find(it.first)==mp2.end()) return false;
            if(mp2[it.first]< it.second) return false;
        }
        return true;

    }
};