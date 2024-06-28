class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> connect(n, 0);
        for(auto it: roads){
            connect[it[0]]++;
            connect[it[1]]++;
        }

        sort(connect.begin(), connect.end());
        long long total=0;
        for(int i=0; i<n; i++){
            total+= connect[i]*(i+1);
        }
        return total;



    }
};