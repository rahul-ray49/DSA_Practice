class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dest) {

        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});

        }

        vector<double>dist(n,0.0);

        priority_queue<pair<double,int>>q;
        q.push({1.0,src});
        dist[src]=1.0;

        while(!q.empty()){

            int node=q.top().second;
            double p=q.top().first;

            q.pop();

            for(auto ele:adj[node]){

                if(dist[ele.first]<dist[node]*ele.second){
                    dist[ele.first]=dist[node]*ele.second;
                    q.push({dist[ele.first],ele.first});
                }

            }
            
        }

        return dist[dest];


        
    }
};