class Solution {
public:
    int dfs(vector<vector<int>>&adj,int node,vector<bool>&hasApple,vector<int>&vis){
        vis[node]=1;
        int time=0;
        for(auto ele : adj[node]){
            if(vis[ele] || ele==node) continue;
            time+=dfs(adj,ele,hasApple,vis);
        }
        if(hasApple[node] || time >0 ) time+=2;
        return time;
      
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int a=dfs(adj,0,hasApple,vis);
        return a==0 ? a : a-2;
    }
};