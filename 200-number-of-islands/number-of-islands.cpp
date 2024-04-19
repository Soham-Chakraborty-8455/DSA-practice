class Solution {
private:
    void dfs(int i, int j, int m, int n, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[i][j]=1;
        int row[]= {0, 1, 0, -1};
        int col[]= {1, 0, -1, 0};
        for(int k=0; k<4; k++){
            int nrow= i+ row[k];
            int ncol= j+ col[k];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==-1 && grid[nrow][ncol]=='1'){
                dfs(nrow, ncol, m, n, vis, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size(), n=grid[0].size(), count=0;
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    dfs(i, j, m, n, vis, grid);
                    count++;
                }
            }
        }
        // for(int i=0; i<m; i++){
        //     for (int j=0; j<n; j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return count;
    }
};