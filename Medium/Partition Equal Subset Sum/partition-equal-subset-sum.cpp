//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int f(int ind, int arr[], int N, int sum, vector<vector<int>>& dp){
        if(ind==N){
            if(sum==0) return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        //take
        int take= 0;
        if(arr[ind]<=sum){
            take= f(ind+1, arr, N, sum-arr[ind], dp);
        }
        int nottake= f(ind+1, arr, N, sum, dp);
        return dp[ind][sum]= take || nottake;
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum= 0;
        for(int i=0; i<N; i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return 0;
        vector<vector<int>> dp(N+1, vector<int> (sum, -1));
        int flag= f(0, arr, N, sum/2, dp);
        return flag;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends