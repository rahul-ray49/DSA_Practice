class Solution {
public:
    bool hasCycle(vector<vector<int>>&adj,vector<int>&vis,vector<int>&recStack,int node){
        vis[node]=1;
        recStack[node]=1;
        for(auto ele:adj[node]){
            if(!vis[ele]){
                bool a=hasCycle(adj,vis,recStack,ele);
                if(a) return true;
            }
            else{
                if(recStack[ele]) return true;
            }
        }
        recStack[node]=0;
        return false;

    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>>adj(colors.size());
        vector<int>indegree(colors.size(),0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>vis(colors.size(),0);
        vector<int>recStack(colors.size(),0);
        for(int i=0;i<colors.size();i++){
            if(!vis[i]){
                bool a=hasCycle(adj,vis,recStack,i);
                if(a) return -1;
            }
        }
        vector<vector<int>>dp(colors.size(),vector<int>(26,0));
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            dp[node][colors[node]-'a']+=1;
            for(auto ele:adj[node]){
                for(int i=0;i<26;i++){
                    dp[ele][i]=max(dp[ele][i],dp[node][i]);
                }
                indegree[ele]--;
                if(indegree[ele]==0){
                    q.push(ele);
                }
            }
        }

       int maxi=0;
       for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            maxi=max(maxi,dp[i][j]);
        }
       }

       return maxi==0 ? -1: maxi;


    }
};