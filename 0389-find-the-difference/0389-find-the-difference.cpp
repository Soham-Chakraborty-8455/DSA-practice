class Solution {
public:
    char findTheDifference(string s, string t) {
        int i=0, cnt=0;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        while(i<t.length()){
            if(s[i]==t[i]){
                i++;
            }
            if(s[i]!=t[i]){
                return t[i];
                break;
            }
        }
        return 'a';
    }
};