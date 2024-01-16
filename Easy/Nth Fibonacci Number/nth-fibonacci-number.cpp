//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    int f(int n, vector<int>& dp){
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        return dp[n]=(f(n-1, dp)+ f(n-2, dp))  % 1000000007;
    }
  public:
    int nthFibonacci(int n){
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int baseF = 1;
        int baseS = 1;
        const int mod = 1e9 + 7;
        for (int i = 3; i <= n; ++i) {
            int tmp = baseF + baseS;
            baseF = baseS;
            baseS = tmp % mod;
        }
        return baseS;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends