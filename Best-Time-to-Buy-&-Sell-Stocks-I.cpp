class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini= prices[0], maxi=0, profit=0;
        for(int i=1; i<prices.size(); i++){
            profit= prices[i]-mini;
            maxi= max(profit, maxi);
            mini= min(mini, prices[i]);
        }
        return maxi;
    }
};
