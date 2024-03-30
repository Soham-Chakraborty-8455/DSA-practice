class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int start = 0, end = 0, total = 0;
        map<int, int> mp;
        int atMostK = 0;

        while (end < nums.size()) {
            mp[nums[end]]++;

            while (mp.size() > k) {
                mp[nums[start]]--;
                if (mp[nums[start]] == 0) {
                    mp.erase(nums[start]);
                }
                start++;
                atMostK = 0; 
            }

            while (mp.size() == k && mp[nums[start]] > 1) {
                mp[nums[start]]--;
                start++;
                atMostK++;
            }

            if (mp.size() == k) {
                total += atMostK + 1; 
            }

            end++;
        }

        return total;
    }
};
