class Solution {
public:
    string reverseVowels(string s) {
        map<char, int> mp;
        mp.insert({'a', 1});
        mp.insert({'e', 1});
        mp.insert({'i', 1});
        mp.insert({'o', 1});
        mp.insert({'u', 1});
        mp.insert({'A', 1});
        mp.insert({'E', 1});
        mp.insert({'I', 1});
        mp.insert({'O', 1});
        mp.insert({'U', 1});
        vector<char> arr;
        string str="";
        for(auto it: s){
            if(mp.find(it)!=mp.end()){
                arr.push_back(it);
                str.push_back('_');
            }
            else{
                str.push_back(it);
            }
        }
        string ans="";
        int ptr=0;
        reverse(arr.begin(), arr.end());
        for(auto it: str){
            if(it=='_'){
                ans.push_back(arr[ptr]);
                ptr++;
            }
            else{
                ans.push_back(it);
            }
        }
        return ans;
    }
};