class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> newm(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                newm[j][n-i-1]= matrix[i][j];
            }
        }
        matrix=newm;
    }
};
