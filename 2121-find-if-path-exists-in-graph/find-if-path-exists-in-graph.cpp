class Solution {
private:
    bool bfs(int node, unordered_map<int, vector<int>>& adjlst, vector<int>& vis, int destination){
        if(node==destination) return true;
        vis[node]= 1;
        bool result=false;
        for(auto it: adjlst[node]){
            if(!vis[it]){
                result= result|| bfs(it, adjlst, vis, destination);
                if(result==true) break;
            }
        }
        return result;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adjlst;
        for(auto it: edges){
            adjlst[it[0]].push_back(it[1]);
            adjlst[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        if(bfs(source, adjlst, vis, destination)) return true;
        return false;

    }
};