class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        unordered_set<int> rows;
        unordered_set<int> column;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    column.insert(j);
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(column.find(j)!= column.end() || rows.find(i)!= rows.end()){
                    matrix[i][j]=0;
                } 
            }
        }
    }
};
