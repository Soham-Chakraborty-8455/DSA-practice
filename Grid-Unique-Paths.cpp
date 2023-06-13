class Solution {
private:
    
int f(int i, int j, vector<vector<int>>& dp){
	//base-case
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	//up
	int up=f(i-1, j, dp);

	//left
	int left= f(i, j-1, dp);

	return dp[i][j]=up+left;
}
public:
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int>(n, -1));
	int i=m-1, j=n-1;
	return f(i,j, dp);
}
};
