class Solution {
public:
    
    vector<int> dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&ans,int node,string& labels){
        vis[node]=1;

        vector<int>freq(26,0);
        vector<int>res;
        for(auto ele : adj[node]){
            if(vis[ele]) continue;
            res=dfs(adj,vis,ans,ele,labels);
            for(int i=0;i<26;i++){
                freq[i]+=res[i];
            }
        }
        freq[labels[node]-'a']++;
        ans[node]=freq[labels[node]-'a'];
        return freq;

    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        vector<int>ans(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<int>res;
        dfs(adj,vis,ans,0,labels);
        return ans;

    }
};