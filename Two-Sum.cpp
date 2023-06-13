class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end()){
                int start=mp[rem];
                int end=i;
                ans.push_back(start);
                ans.push_back(end);
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};





//Optimal: (Not for LeetCode/Coding Ninjas)
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}
