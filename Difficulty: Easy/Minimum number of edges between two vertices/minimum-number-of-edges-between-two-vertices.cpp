class Solution {
  public:
    int minEdges(int V, vector<vector<int>>& edges, int u, int v) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);
        queue<pair<int,int>>q;
        q.push({u,0});
        vis[u]=1;
        while(!q.empty()){
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(node==v) return steps;
            for(auto ele:adj[node]){
                if(vis[ele]) continue;
                q.push({ele,steps+1});
                vis[ele]=1;
            }
        }
        return -1;
        
    }
};
