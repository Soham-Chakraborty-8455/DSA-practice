class Solution {
private:
    void dfs(int ind, map<int, vector<int>> &mp, vector<int> &res, set<int> &visited){
        if(mp.find(ind) == mp.end()) return;

        for(auto it : mp[ind]){
            if(visited.find(it) == visited.end()){
                res.push_back(it);
                visited.insert(it);
                dfs(it, mp, res, visited);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        map<int, vector<int>> mp;
        for(auto it : edges){
            mp[it[1]].push_back(it[0]);
        }
        for(int i = 0; i < n; i++){
            vector<int> res;
            set<int> visited;
            dfs(i, mp, res, visited);
            sort(res.begin(), res.end());
            ans.push_back(res);
        }

        return ans;
    }
};
