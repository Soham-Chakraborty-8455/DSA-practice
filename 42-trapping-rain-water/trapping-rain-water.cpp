class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int> leftmax (n, 0); 
        vector<int> rightmax (n, 0);
        leftmax[0]= height[0];
        rightmax[n-1]= height[n-1];
        for(int i=1; i<height.size(); i++){
            leftmax[i]= max(leftmax[i-1], height[i]);
        }
        for(int i=n-2; i>=0; i--){
            rightmax[i]= max(rightmax[i+1], height[i]);
        }
        int sum=0;
        for(int i=0; i<height.size(); i++){
            // cout<<leftmax[i]<<" "<<rightmax[i]<< endl;
            sum+= min(leftmax[i], rightmax[i]) - height[i];
        }
        return sum;
    }
};
// [4 4 4 4 4 5]
// [5 5 5 5 5 5]