class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        vector<int> row, col;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        int minr=INT_MAX, minc=INT_MAX, maxr=INT_MIN, maxc=INT_MIN;
        for(int i=0; i<row.size(); i++){
            minr= min(minr, row[i]);
            minc= min(minc, col[i]);
            maxr= max(maxr, row[i]);
            maxc= max(maxc, col[i]);
        }
        int len= maxc-minc;
        int wid= maxr-minr;
        return (len+1)*(wid+1);
    }
};