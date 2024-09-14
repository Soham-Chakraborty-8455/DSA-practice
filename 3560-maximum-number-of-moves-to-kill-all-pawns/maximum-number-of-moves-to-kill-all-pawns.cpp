#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Directions a knight can move
    const vector<pair<int, int>> dirs = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    // Function to compute minimal knight moves from (sx, sy) to all positions
    vector<vector<int>> computeDistances(int sx, int sy) {
        // Initialize distance grid
        vector<vector<int>> dist(50, vector<int>(50, -1));
        queue<pair<int, int>> q;
        q.push({sx, sy});
        dist[sx][sy] = 0;
        
        while (!q.empty()) {
            pair<int, int> current = q.front(); q.pop();
            int x = current.first;
            int y = current.second;
            for (auto &d : dirs) {
                int nx = x + d.first;
                int ny = y + d.second;
                if (nx >=0 && nx < 50 && ny >=0 && ny < 50 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    }
    
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int N = positions.size();
        // Assign index 0 to starting position
        // Assign indices 1 to N to pawns
        vector<pair<int, int>> allPositions;
        allPositions.emplace_back(kx, ky); // index 0
        for(auto &p : positions){
            allPositions.emplace_back(p[0], p[1]);
        }
        // Precompute distances
        // distance[i][j] = minimal knight moves from position i to position j
        vector<vector<int>> distance(N+1, vector<int>(N+1, 0));
        // Precompute distances for each position
        // To optimize, compute all distances first
        // Compute distances from each position to all other positions
        // Then fill distance[i][j] accordingly
        // Since N is up to 15, it's feasible
        // First, compute distance grids for all positions
        vector<vector<vector<int>>> allDist(N+1, vector<vector<int>>());
        for(int i=0;i<=N;i++){
            int sx = allPositions[i].first;
            int sy = allPositions[i].second;
            allDist[i] = computeDistances(sx, sy);
        }
        // Now, fill distance[i][j]
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                if(i == j){
                    distance[i][j] = 0;
                }
                else{
                    int tx = allPositions[j].first;
                    int ty = allPositions[j].second;
                    distance[i][j] = allDist[i][tx][ty];
                }
            }
        }
        // Now, implement DP with memoization
        // State: pos (0 to N), mask (0 to (1<<N)-1)
        // Memoization table
        // Initialize memo to -1
        int size = N+1;
        int maskSize = (1 << N);
        // Using vector of vectors
        // To save space, use a single vector and compute index as pos * maskSize + mask
        // Initialize with -1
        vector<long long> memoTable((N+1) * (1 << N), -1LL);
        
        // Recursive DP function with memoization
        // Using lambda for recursion
        // Return type is long long to prevent overflow, but can be int as per constraints
        // Use memoTable to store results
        function<long long(int, int)> dp = [&](int pos, int mask) -> long long {
            if(mask == 0){
                return 0;
            }
            // Compute index for memoTable
            int index = pos * (1 << N) + mask;
            if(memoTable[index] != -1){
                return memoTable[index];
            }
            // Determine whose turn it is
            // Number of pawns captured so far is N - count_bits(mask)
            int captured = N - __builtin_popcount(mask);
            bool isAlice = (captured % 2 == 0);
            if(isAlice){
                // Alice's turn: maximize the total sum
                long long best = LLONG_MIN;
                for(int j=0; j<N; j++){
                    if(mask & (1 << j)){
                        // Capture pawn j+1
                        int nextPos = j+1;
                        int newMask = mask ^ (1 << j);
                        long long total = distance[pos][nextPos] + dp(nextPos, newMask);
                        if(total > best){
                            best = total;
                        }
                    }
                }
                memoTable[index] = best;
                return best;
            }
            else{
                // Bob's turn: minimize the total sum
                long long best = LLONG_MAX;
                for(int j=0; j<N; j++){
                    if(mask & (1 << j)){
                        // Capture pawn j+1
                        int nextPos = j+1;
                        int newMask = mask ^ (1 << j);
                        long long total = distance[pos][nextPos] + dp(nextPos, newMask);
                        if(total < best){
                            best = total;
                        }
                    }
                }
                memoTable[index] = best;
                return best;
            }
        };
        
        // Initial mask: all pawns are present
        int initialMask = (N == 0) ? 0 : ((1 << N) -1);
        // Compute the result
        long long result = dp(0, initialMask);
        // Since the output is expected to be int, cast it
        return (int)result;
    }
};
