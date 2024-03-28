class Solution {
private:
    bool f(string s, string str){
        sort(s.begin(), s.end());
        sort(str.begin(), str.end());
        return (s==str);
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int l=0, r=s1.size()-1;
        string s="";
        for(int i=l; i<=r; i++){
            s.push_back(s2[i]);
        }
        
        while(r<s2.length()){
            if(f(s1, s)) return true;
            s.erase(0, 1);
            l++;
            r++;
            s.push_back(s2[r]);
        }
        return false;


    }
};