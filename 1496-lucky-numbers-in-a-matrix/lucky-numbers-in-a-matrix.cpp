class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> minirow, minicol;
        int m= matrix.size(), n= matrix[0].size();
        for(int i=0; i<m; i++){
            int mini=INT_MAX;
            for(int j=0; j<n; j++){
                if(matrix[i][j]<mini) mini= matrix[i][j];
            }
            // cout<<mini<<" ";
            minirow.push_back(mini);
        }
        cout<<endl;
        cout<<endl;
        for(int i=0; i<n; i++){
            int maxi=INT_MIN;
            for(int j=0; j<m; j++){
                if(matrix[j][i]>maxi) maxi= matrix[j][i];
                // cout<<matrix[j][i]<<" ";
            }
            // cout<<maxi<<" ";
            minicol.push_back(maxi);
        }
        vector<int> ans;
        for(int i=0; i<minirow.size(); i++){
            for(int j=0; j<minicol.size(); j++){
                if(minirow[i]==minicol[j]){
                    ans.push_back(minirow[i]);
                    break;
                }
            }
        }
        return ans;
    }
};