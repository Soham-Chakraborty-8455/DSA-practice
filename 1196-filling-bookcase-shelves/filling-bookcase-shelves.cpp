class Solution {
private:
    // Using memoization to store results of subproblems
    vector<int> dp;
    
    int f(int ind, vector<vector<int>>& books, int shelfWidth) {
        if (ind == books.size()) return 0; // Base case
        
        if (dp[ind] != -1) return dp[ind]; // Check memoization table
        
        int sumw = 0;
        int maxi = 0;
        int minHeight = INT_MAX; // Initialize to max value
        
        // Try to place books on the current shelf
        for (int i = ind; i < books.size(); ++i) {
            sumw += books[i][0]; // Add book width
            
            if (sumw > shelfWidth) break; // If it exceeds, stop
            
            maxi = max(maxi, books[i][1]); // Max height of current shelf
            
            // Try the next configuration
            int height = maxi + f(i + 1, books, shelfWidth);
            minHeight = min(minHeight, height);
        }
        
        return dp[ind] = minHeight; // Store and return result
    }
    
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp = vector<int>(books.size(), -1); // Initialize memoization table
        return f(0, books, shelfWidth); // Start from the first book
    }
};
