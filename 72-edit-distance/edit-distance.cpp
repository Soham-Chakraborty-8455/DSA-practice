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
        return f(m, n, word1, word2, dp);
    }
};