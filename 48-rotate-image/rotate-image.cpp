class Solution {
private:
    void swap(int &a, int &b){
        int temp= a;
        a=b;
        b=temp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<matrix.size(); i++){
            int start=0, end= matrix[i].size()-1;
            while(start<end){
                swap(matrix[i][start], matrix[i][end]);
                start++;
                end--;
            }
        }
    }
};