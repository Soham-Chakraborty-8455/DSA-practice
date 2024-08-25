class Solution {
private:
    int f(int i, int j, string str1, string str2, vector<vector<int>>& dp ){
        if(j==0) return i;
        if(i==0) return j;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i-1]==str2[j-1]) return f(i-1, j-1, str1, str2, dp);
        int x= 1+ f(i-1, j, str1, str2, dp);
        int y= 1 + f(i, j-1, str1, str2, dp);
        int z= 1+ f(i-1, j-1, str1, str2, dp);
        return dp[i][j]= min(x, min(y, z));
    }
public:
    int minDistance(string word1, string word2) {
        int m= word1.length();
        int n= word2.length();
        vector<vector<int>> dp (m+1, vector<int> (n+1, -1));
        for(int i=0; i<m+1; i++){
            dp[i][0] = i;
        }
        for(int j=0; j<n+1; j++){
            dp[0][j] = j;
        }
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]= dp[i-1][j-1];
                else{
                    int x= 1+ dp[i-1][j];
                    int y= 1+ dp[i][j-1];
                    int z= 1+ dp[i-1][j-1];
                    dp[i][j]= min(x, min(y, z));
                }
            }
        }
        return dp[m][n];
    }
};