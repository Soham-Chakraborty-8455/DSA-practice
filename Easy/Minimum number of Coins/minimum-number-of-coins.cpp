//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int f(int ind, int N, vector<int>& nums, vector<int>& output){
        if(N==0) return 0;
        if(ind==0){
            if(N%nums[0]==0){
                output.push_back(nums[0]);
                return N/nums[0];
            }
            else return 1e7;
        }
        
        int take= 1e7;
        if(nums[ind]<=N){
            output.push_back(nums[ind]);
            take= 1 + f(ind, N- nums[ind], nums, output);
        }
        int nottake= 0 + f(ind-1, N, nums, output);
        
        return min(take, nottake);
    }
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>v{2000,500,200,100,50,20,10,5,2,1};
        vector<int>ans;
        
        int i=0;
        while(N)
        {
            if(N<v[i])
            {
                i++;
            }
            else 
            {
                N=N-v[i];
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends