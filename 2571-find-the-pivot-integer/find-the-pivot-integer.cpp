class Solution {
public:
    int pivotInteger(int n) {
        if(n==1){
            return 1;
        }
        for(int i=1; i<=n; i++){
            int t1= (i*(i+1))/2;
            int t2= (n*(n+1))/2 - (i*(i-1))/2;
            if(t1==t2){
                return i;
            }
        }
        return -1;
    }
};