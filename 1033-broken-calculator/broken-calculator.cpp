class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;

        while(startValue!=target){
            if(startValue>=target) {
                ans+=startValue-target;
                break;
            }
            if(target%2==0){
                target=target/2;
                ++ans;
            }
            else{
                target=target+1;
                ++ans;
            }
        }
        return ans;
    }
};