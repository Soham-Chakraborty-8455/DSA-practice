class Solution {
private:
    bool safe(int ind, int i, vector<string> output, int n){
        //up, topleft, topright
        int row= ind-1, col= i;
        while(row>=0){
            if(output[row][col]=='Q') return false;
            row--;
        }
        row= ind-1, col= i-1;
        while(row>=0 && col>=0){
            if(output[row][col]=='Q') return false;
            row--;
            col--;
        }
        row= ind-1, col=i+1;
        while(row>=0 && col<n){
            if(output[row][col]=='Q') return false;
            row--;
            col++;
        }
        return true;
    }
    void f(int ind, int n, int q, vector<string> output, vector<vector<string>>& ans){
        if(ind==n){
            if(q==n) ans.push_back(output);
            return;
        }
        for(int i=0; i<n; i++){
            if(safe(ind, i, output, n)){
                output[ind][i]='Q';
                q++;
                f(ind+1, n, q, output, ans);
                q--;
                output[ind][i]='.';
            }
            // output[ind].push_back('.');
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> output (n, string(n, '.'));
        f(0, n, 0, output, ans);
        return ans;
    }
};