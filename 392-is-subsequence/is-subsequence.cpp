class Solution {
private:
    bool f(int i, int j, string s, string t){
        if(i<0) return true;
        if(j<0) return false;
        
        if(s[i]==t[j]){
            return f(i-1, j-1, s, t);
        }
        return f(i, j-1, s, t);
    }
public:
    bool isSubsequence(string s, string t) {
        int n= s.length(), m= t.length();
        return f(n-1, m-1, s, t);
    }
};