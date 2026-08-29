class Solution {
  public:
  int dp[100001][4];
    int solve(int i,int j,vector<vector<int>>& mat,int n)
    {
        if(i>=n)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=INT_MAX;
        for(int p=0;p<3;p++)
        {
            if(p!=j)
            ans=min(ans,mat[i][j]+solve(i+1,p,mat,n));
        }
        return dp[i][j]=ans;
    }
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int j=0;j<3;j++)
        {
            ans=min(ans,solve(0,j,mat,n));
        }
        return ans;
    }
};