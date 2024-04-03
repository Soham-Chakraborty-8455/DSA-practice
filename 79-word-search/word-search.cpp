class Solution {
private:
    bool dfs(int i, int j, int ind, bool flag, vector<vector<char>>& board, string word, vector<vector<int>>& vis){
        if(ind==word.size()) return true;
    
        if(i>=0 && j>=0 && i<board.size() && j<board[0].size() && !vis[i][j]){
            
            if (board[i][j]!=word[ind]) return false;
            else {
                vis[i][j]=1;
                // cout<<board[i][j]<<endl;
            }
        }
        else{
            return false;
        };
        bool f= (dfs(i+1, j, ind+1, flag, board, word, vis) ||
        dfs(i-1, j, ind+1, flag, board, word, vis) ||
        dfs(i, j+1, ind+1, flag, board, word, vis) ||
        dfs(i, j-1, ind+1, flag, board, word, vis)
        );
        vis[i][j] = 0;
        return f;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool flag= false;
        vector<vector<int>> vis(board.size(), (vector<int>(board[0].size(), 0)));
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    bool ans= dfs(i, j, 0, false, board, word, vis);
                    if(ans==true) return true;
                }
            }
        }
        return flag;
    }
};