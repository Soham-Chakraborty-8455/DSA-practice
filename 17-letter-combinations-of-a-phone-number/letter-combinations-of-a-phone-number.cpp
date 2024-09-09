class Solution {
private:
    void f(int ind, string& digits, map<char, string>& mp, string& output, vector<string>& ans){
        if(ind==digits.length()){
            if(output.length()==digits.length()) ans.push_back(output);
            return;
        }
        for(auto it: mp[digits[ind]]){
            output.push_back(it);
            f(ind+1, digits, mp, output, ans);
            output.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        map<char, string> mp;
        mp['1']="";
        mp['2']="abc";
        mp['3']= "def";
        mp['4']= "ghi";
        mp['5'] ="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        mp['0']=" ";
        vector<string> ans;
        string output="";
        f(0, digits, mp, output, ans);
        return ans;
    }
};