class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        // Handle edge case: array is already sorted
        if (nums[low] < nums[high]) {
            return nums[low];
        }

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid is greater than both high and low, the minimum is in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Otherwise, the minimum is in the left half (including mid)
            else {
                high = mid;
            }
        }

        // At this point, low == high, pointing to the minimum element
        return nums[low];
    }
};
