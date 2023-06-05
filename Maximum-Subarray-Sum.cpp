#include <bits/stdc++.h> 
long long maxSubarraySum(int nums[], int n)
{
    long long sum=0;
    long long maxi=INT_MIN;
    if(n==1){
        return nums[0];
    }
    for(int i=0; i<n; i++){
        sum+=nums[i];
        maxi=max(sum, maxi);
        if(sum<0){
            sum=0;
        }
    }
    if(maxi<0) return 0;
    return maxi;
}
