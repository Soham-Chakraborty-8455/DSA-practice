class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int f=0, t=0,tw=0;
       for(auto it: bills){
        if(it==5){
            f++;
        }
        else if(it==10){
            if(f<0) return false;
            f--;
            t++;
        }
        else{
            if(f<0) return false;
            if(t>=1 && f>=1){
                t--;
                f--;
                tw++;
            }
            else if(f>=3){
                f-=3;
                tw++;
            }
            else return false;
            
        }
       } 
       return true;
    }
};