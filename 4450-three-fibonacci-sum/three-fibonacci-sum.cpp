class Solution {
public:
    bool threeFibonacciSum(int n) {
        if(n%2!=0||n==0) return false;
        int d=n/2;
        int a=0;
        int b=1;
        for( b=1;b<=d;){
            long long c=a+b;
            if(c==d) return true;
            a=b;
            b=c;
        }
        return false;

    }
};