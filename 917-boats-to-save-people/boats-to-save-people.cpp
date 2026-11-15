class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
        int j=people.size()-1;
        int ans=0;
        sort(people.begin(),people.end());
        while(i<=j){
            int w1=people[j];
            int remaining=limit-w1;
            if(people[i]<=remaining){
                ++i;
            }
            --j;
            ++ans;
        }
        return ans;
    }
};