class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int &maxi){
        vis[node]=1;
        maxi++;
        for(auto ele:adj[node]){
            if(vis[ele]) continue;
            dfs(ele,adj,vis,maxi);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>>adj(bombs.size());

        for(int i=0;i<bombs.size();i++){
            int x1=bombs[i][0];
            int y1=bombs[i][1];
            int r1=bombs[i][2];
            for(int j=0;j<bombs.size();j++){
                if(i==j) continue;
                int x2=bombs[j][0];
                int y2=bombs[j][1];
                int r2=bombs[j][2];

                long long distSquare=pow(x2-x1,2)+pow(y2-y1,2);
                long long radiusSquare=pow(r1,2);
                if(radiusSquare>=distSquare){
                    adj[i].push_back(j);
                }

            }
        }
        vector<int>vis(bombs.size(),0);
        int ans=0;
        for(int i=0;i<adj.size();i++){
            int maxi=0;
            dfs(i,adj,vis,maxi);
            ans=max(ans,maxi);
            fill(vis.begin(),vis.end(),0);
        }
        return ans;
    }
};