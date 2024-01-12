//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int f(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(i==s.length() && j==t.length()) return 0;
        if(i== s.length() && j<t.length()) return t.length()-j;
        if(i<s.length() && j== t.length()) return s.length()-i;
        if(dp[i][j]!= -1) return dp[i][j];
        //match
        if(s[i]==t[j]){
            return dp[i][j]= 0+ f(i+1, j+1, s, t, dp);
        }
        //notmatch
        int insert= 1e7;
        int remove= 1e7;
        int replace= 1e7;
        if(s[i]!=t[j]) insert= 1+ f(i, j+1, s, t, dp);
        if(s[i]!=t[j]) remove= 1+ f(i+1, j, s, t, dp);
        if(s[i]!= t[j]) replace= 1+ f(i+1, j+1, s, t, dp);
        return dp[i][j]= min(insert, min(remove, replace));
    }
  public:
    int editDistance(string s, string t) {
        // Code here
        int ns= s.length();
        int nt= t.length();
        vector<vector<int>> dp(ns+1, vector<int>(nt+1, -1));
        return f(0, 0, s, t, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends