class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mp,int node,vector<int>&traversal){


        while(!mp[node].empty()){
            int u=mp[node].back();
            mp[node].pop_back();
            dfs(mp,u,traversal);
        }
        traversal.push_back(node);

    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<pairs.size();i++){
            int u=pairs[i][0];
            int v=pairs[i][1];
            mp[u].push_back(v);
        }
        unordered_map<int,int>indegree;
        unordered_map<int,int>outdegree;

        for(auto ele:mp){
            int OD=ele.second.size();
            outdegree[ele.first]=OD;
            for(auto neighbour:ele.second){
                indegree[neighbour]++;
            }
        }

        int start=-1;
        for(auto ele:mp){
            if(outdegree[ele.first]-indegree[ele.first]==1){
                start=ele.first;
                break;
            }
        }
        if(start==-1){
            for(auto ele:outdegree){
               start=ele.first;
               break;
            }
            
        }

        vector<int>traversal;
        dfs(mp,start,traversal);
        reverse(traversal.begin(),traversal.end());

        vector<vector<int>>ans;

        for(int i=0;i<traversal.size()-1;i++){
            int u=traversal[i];
            int v=traversal[i+1];
            ans.push_back({u,v});
        }
        return ans;
    }
};