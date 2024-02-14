class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0; i<s.length(); i++){
            if(iswalnum(s[i])) str.push_back(s[i]);
        }
        for(int i=0; i<str.length(); i++){
            str[i]= (char)tolower(str[i]);
        }
        int start=0, end=str.length()-1;
        bool flag=true;
        while(start<end){
            if(str[start]==str[end]){
                start++;
                end--;
            }
            else{
                flag=false;
                break;
            }
        }
        return flag;
    }
};