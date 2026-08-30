class Solution {
public:
    int dfs(int node,vector<int>&vis,vector<vector<int>>&adj,string &s,int& maxi){
        vis[node]=1;
        int first_longest_path=0;
        int second_longest_path=0;
        
        for(auto ele:adj[node]){
            if(vis[ele]) continue;
            int a=dfs(ele,vis,adj,s,maxi);
            if(s[node]==s[ele]) a=0;
            if(a>=first_longest_path){
                second_longest_path=first_longest_path;
                first_longest_path=a;
            }
            else{
                if(first_longest_path>=a&&a>=second_longest_path){
                    second_longest_path=a;
                }
            }
            maxi=max(maxi,1+first_longest_path+second_longest_path);
        }

        return 1+max(first_longest_path,second_longest_path);

    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>>adj(parent.size());
        for(int i=0;i<parent.size();i++){
            int par=parent[i];
            if(par==-1) continue;
            adj[par].push_back(i);
            adj[i].push_back(par);
        }
        vector<int>vis(parent.size(),0);
        int maxi=0;
        int a=dfs(0,vis,adj,s,maxi);
        maxi=max(maxi,a);
        return maxi;

    }
};