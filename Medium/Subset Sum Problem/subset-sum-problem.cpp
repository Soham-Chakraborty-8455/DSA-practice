//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
private:
    int f(int ind, vector<int>& arr, int sum, vector<vector<int>>& dp){
        if(ind==arr.size()){
            if(sum==0) return 1;
            else return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        //take
        int take=0;
        if(arr[ind]<=sum){
            take= f(ind+1, arr, sum-arr[ind], dp);
        }
        //nottake
        int nottake= f(ind+1, arr, sum, dp);
        return dp[ind][sum]= take || nottake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n= arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return f(0, arr, sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends