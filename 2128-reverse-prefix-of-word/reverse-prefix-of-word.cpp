class Solution {
public:
    string reversePrefix(string word, char ch) {
        int start=0, end=0;
        for(int i=0; i<word.size(); i++){
            if(word[i]==ch){
                end=i;
                break;
            }
        }
        while(start<end){
            swap(word[start], word[end]);
            start++;
            end--;
        }
        return word;
    }
};