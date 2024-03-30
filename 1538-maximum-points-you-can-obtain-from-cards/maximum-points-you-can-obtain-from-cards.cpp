class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0, rsum=0;
        int start=k-1, end=cardPoints.size()-1;
        for(int i=0; i<k; i++){
            lsum+= cardPoints[i];
        }
        // cout<<"start:"<< start<<endl;
        // cout<<lsum<<" "<<rsum<<endl;
        int maxi=lsum;
        while(start>=0){
            lsum-=cardPoints[start];
            start--;
            rsum+= cardPoints[end];
            end--;
            // cout<<lsum<<" "<<rsum<<endl;
            maxi= max(maxi, lsum+rsum);
        }
        return maxi;
    }
};