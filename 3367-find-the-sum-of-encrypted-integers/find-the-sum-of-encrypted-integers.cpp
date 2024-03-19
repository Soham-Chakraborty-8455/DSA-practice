class Solution {
private:
    int encrypt(int number){
        int digi=0;
        int maxi=0;
        while(number!=0){
            int ele= number % 10;
            number= number/10;
            digi++;
            maxi= max(maxi, ele);
        }
        int num=0;
        while(digi--){
            num= 10*num + maxi;
        }
        return num;
    }
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+= encrypt(nums[i]);
        }
        return sum;
    }
};