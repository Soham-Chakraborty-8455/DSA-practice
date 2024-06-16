class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int64_t max_reachable = 0;
        int ans = 0;
        for (int i : nums) {
            while (i > max_reachable + 1 && max_reachable < n) {
                max_reachable += (max_reachable+1);
                ++ans;
            }
            max_reachable += i;
            if (max_reachable >= n) return ans;
        }
        while (max_reachable < n) {
            max_reachable += max_reachable + 1;
            ++ans;
        }
        return ans;
    }
};