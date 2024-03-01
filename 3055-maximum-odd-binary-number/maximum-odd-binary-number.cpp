class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string str="";
        int cnt=0;
        for(auto it:s){
            if(it=='1') cnt++;
        }
        if(cnt>1){
            for(int i=0; i<cnt-1; i++){
                str.push_back('1');
            }
            int len0= s.length()-cnt;
            for(int i=0; i<len0; i++){
                str.push_back('0');
            }
            str.push_back('1');
            return str;
        }
        else if(cnt==1){
            int len0= s.length()-cnt;
            for(int i=0; i<len0; i++){
                str.push_back('0');
            }
            str.push_back('1');
            return str;
        }
        else if(cnt==0){
            return s;
        }
        return str;
    }
};