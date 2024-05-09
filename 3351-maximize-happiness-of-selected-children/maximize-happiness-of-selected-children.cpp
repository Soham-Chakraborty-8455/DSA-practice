class Solution {
// private:
//     long long f(int ind, vector<int>& happiness, int k, long long sum){
//         if(ind==happiness.size()) return 0;
//         //take k
        
        
        
//         //nottake k
//     }
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum=0;
        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());
        for(int i=0; i<k; i++){
            happiness[i]= happiness[i]-i;
            if (happiness[i]<0) happiness[i]=0;
            // cout<<happiness[i]<<endl;
            sum+= happiness[i];            
        }
        return sum;
    }
};