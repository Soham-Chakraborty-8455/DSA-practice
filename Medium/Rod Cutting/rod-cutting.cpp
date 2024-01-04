//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int f(int ind, int price[], int n, int len, vector<vector<int>>& dp){
        if(len>n) return 0;
        if(ind>=n) return 0;
        if(dp[ind][len]!=-1) return dp[ind][len];
        //take
        int take=INT_MIN;
        if(len+ind+1<=n){
            take= price[ind]+ f(ind, price, n, len+ind+1, dp);
        }
        //nottake
        int nottake= 0 + f(ind+1, price, n, len, dp);
        return dp[ind][len]= max(take, nottake);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return f(0, price, n, 0, dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends