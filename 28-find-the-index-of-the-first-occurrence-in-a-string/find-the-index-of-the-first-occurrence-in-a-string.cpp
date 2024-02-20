class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=-1;
        // for(int i=0; i<haystack.size(); i++){
        //     int start= 0, end= needle.length();
        //     if(haystack[i]==needle[start]){
        //         int j=i;
        //         bool flag=true;
        //         while(start<end){
        //             if(haystack[j]!=needle[start]){
        //                 flag= false;
        //             }
        //             else{
        //                 start++;
        //                 j++;
        //             }
        //         }
        //         if(flag=true){
        //             ans= i;
        //             break;
        //         }
        //     }
        // }
        ans= haystack.find(needle);
        return ans;
    }
};