class Solution {
  public:
    vector<string> generateGrayCodes(int n) {
        // code here
        if(n==1) return {"0","1"};
        
        vector<string>ans;
        ans.push_back("0");
        ans.push_back("1");
        for(int i=2;i<=n;i++){
            int sz=ans.size();
            for(int j=sz-1;j>=0;j--){
                ans.push_back(ans[j]);
            }
            int oneHalf=ans.size()/2;
            for(int k=0;k<oneHalf;k++){
                ans[k]='0'+ans[k];
            }
            for(int k=oneHalf;k<ans.size();k++){
                ans[k]='1'+ans[k];
            }
        }
        return ans;
    }
};