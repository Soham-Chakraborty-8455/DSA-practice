//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int f(int i, int j, int N, vector<vector<int>>& Matrix, vector<vector<int>>& dp){
        if(i==0) return Matrix[0][j];
        if(j<0 || j>=N) return -1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up= Matrix[i][j]+ f(i-1, j, N, Matrix, dp);
        int ur= Matrix[i][j] + f(i-1, j+1, N, Matrix, dp);
        int ul= Matrix[i][j] + f(i-1, j-1, N, Matrix, dp);
        return dp[i][j]= max(up, max(ul, ur));
    }
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
    //     vector<vector<int>> dp(N+1, vector<int> (N+1, -1));
    //     int maxi=0;
    //     for(int j=0; j<N; j++){
    //         int val= f(N-1, j, N, Matrix, dp);
    //         maxi= max(maxi, val); 
    //     }
    //     return maxi;
        vector<int> prev(N, 0);
        
        for(int j=0;j<N;j++) prev[j] = Matrix[0][j];
        
        for(int i=1;i<N;i++){
            vector<int> cur(N, 0);
            for(int j=0;j<N;j++){
                int up = Matrix[i][j] + prev[j];
                
                int ld = Matrix[i][j];
                (j >= 0)? ld += prev[j-1] : ld += -1e9;
                
                int rd = Matrix[i][j];
                (j+1 < N)? rd += prev[j+1] : rd += -1e9;
                
                cur[j] = max(up, max(ld, rd));
            }
            prev = cur;
        }
        
        int maxi = INT_MIN;
        
        for(int j=0;j<N;j++){
            maxi = max(maxi, prev[j]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends