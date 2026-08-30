class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>ans;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }

        return ans;

    }
};