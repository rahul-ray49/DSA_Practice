class Solution {
public:
    void dfs(unordered_map<string,vector<string>>&adj,string node,vector<string>&ans){
        while(!adj[node].empty()){
            string u=adj[node].back();
            adj[node].pop_back();
            dfs(adj,u,ans);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string,vector<string>>adj;

        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }

        for(auto &ele:adj){
            sort(ele.second.rbegin(),ele.second.rend());
        }

        unordered_map<string,int>outdegree;
        unordered_map<string,int>indegree;

        for(auto mp:adj){
            int OD=mp.first.size();
            outdegree[mp.first]=OD;
            for(auto neighbor:mp.second){
                indegree[neighbor]++;
            }
        }
        string start="JFK";

        vector<string>ans;

        dfs(adj,start,ans);
        reverse(ans.begin(),ans.end());
        return ans;

    }
};