class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto it:details){
            if(it[11]=='6' && it[12]!='0') cnt++;
            else if(it[11]=='7' || it[11]=='8' || it[11]=='9') cnt++;
        }
        return cnt;
    }
};