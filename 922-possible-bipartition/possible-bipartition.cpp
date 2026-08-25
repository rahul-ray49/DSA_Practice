class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n,-1);
        vector<vector<int>>adj(n);
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto ele : adj[node]){
                        if(color[ele]==-1){
                            color[ele]=!(color[node]);
                            q.push(ele);
                        }
                        else{
                            if(color[ele]==!color[node]){
                                continue;
                            }
                            else{
                                if(color[ele]==color[node]) return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};