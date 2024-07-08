class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i = 0; i < n; i++){
            arr.push_back(i + 1);
        }
        int ind = 0;
        while(arr.size() > 1){
            int rem = (ind + k - 1) % n;  
            arr.erase(arr.begin() + rem);
            ind = rem;
            n--; 
        }
        return arr.front();
    }
};
