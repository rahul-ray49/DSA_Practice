class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ans(n+1);
        ans[1]=1;
        int i2=1;
        int i3=1;
        int i5=1;
        for(int i=2;i<=n;i++){
            int num1=ans[i2]*2;
            int num2=ans[i3]*3;
            int num3=ans[i5]*5;

            int mini=min({num1,num2,num3});
            ans[i]=mini;
            if(num1==mini){
                i2++;
            }
            if(num2==mini){
                i3++;
            }
            if(num3==mini){
                i5++;
            }
        }
        return ans[n];
    }
};