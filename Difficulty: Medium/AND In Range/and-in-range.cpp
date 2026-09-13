class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit1=l>>i;
            int bit2=r>>i;
            if(bit1==bit2){
                ans=ans|(bit1<<i);
            }
        }
        return ans;
    }
};
