class Solution {
public:

    bool dfs(vector<vector<int>>&adj,int node,vector<int>&vis){
        vis[node]=1;
        for(auto ele:adj[node]){
            if(!vis[ele]){
                bool a=dfs(adj,ele,vis);
                if(a) return true;
            }
            else{
                if(vis[ele]){
                    return true;
                }
            }
        }
        return false;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>>adj(n);
        int parent=-1;
        vector<int>noPointers(n,0);
        for(int i=0;i<n;i++){
            int LC=leftChild[i];
            int RC=rightChild[i];
            if(LC!=-1){
                adj[i].push_back(LC);
                noPointers[LC]=1;
            }
            if(RC!=-1){
                adj[i].push_back(RC);
                noPointers[RC]=1;
            }
        }

        for(int i=0;i<n;i++){
            if(noPointers[i]==0){
                parent=i;
                break;
            }
        }

        if(parent==-1) return false;

       

        vector<int>vis(n,0);

        bool a=dfs(adj,parent,vis);

        if(a) return false;

        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }

        return true;
    }
};