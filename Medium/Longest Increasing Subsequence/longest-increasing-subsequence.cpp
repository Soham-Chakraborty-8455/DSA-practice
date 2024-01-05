//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    private:
    // int f(int ind, int prev, int a[], int n, vector<vector<int>>& dp){
    //     if(ind>=n) return 0;
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     //take
    //     int take= -1e7;
    //     if( prev==-1 || a[ind]>a[prev]){
    //         take= 1+ f(ind+1, prev, a, n, dp);
    //     }
    //     //nottake
    //     int nottake= 0+ f(ind+1, prev, a, n, dp);
    //     return dp[ind][prev+1]= max(take, nottake);
    // }
    int getAns(int a[], int n, int ind, int prev_index, vector<vector<int>>& dp) {
    // Base condition
    if (ind == n)
        return 0;
        
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(a, n, ind + 1, prev_index, dp);
    
    int take = 0;
    
    if (prev_index == -1 || a[ind] > a[prev_index]) {
        take = 1 + getAns(a, n, ind + 1, ind, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> temp;
    temp.push_back(a[0]);

    int len = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] > temp.back()) {
            // If arr[i] is greater than the last element of temp, extend the subsequence
            temp.push_back(a[i]);
            len++;
        } else {
            // If arr[i] is not greater, replace the element in temp with arr[i]
            int ind = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            temp[ind] = a[i];
        }
    }

    return len;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends