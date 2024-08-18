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
        sort(row.begin(),row.end());
        sort(col.begin(), col.end());
        int len= row[row.size()-1] - row[0];
        int wid= col[col.size()-1] - col[0];
        return (len+1)*(wid+1);
    }
};