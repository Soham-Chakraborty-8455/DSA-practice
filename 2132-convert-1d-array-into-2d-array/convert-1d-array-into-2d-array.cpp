class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {}; 
        }
        vector<vector<int>> nums (m, vector<int> (n, -1));
        for(int i = 0; i < original.size(); i++) {
            int row = i / n;
            int col = i % n;
            nums[row][col] = original[i];
        }
        return nums;

    }
};