class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n=people.size();
        int left=0, right=n-1, boat=0;
        while(left<=right){
            if(people[left]+people[right]<=limit){
                left++;
            }
            right--;
            boat++;
        }
        return boat;
    }
};