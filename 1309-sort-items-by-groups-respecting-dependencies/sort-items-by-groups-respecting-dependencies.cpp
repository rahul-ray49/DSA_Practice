class Solution {
public:
    bool hasCycle(int node,vector<vector<int>>&adjList1,vector<int>&vis,vector<int>&recStack){
        vis[node]=1;
        recStack[node]=1;
        for(auto ele:adjList1[node]){
            if(!vis[ele]){
                bool a=hasCycle(ele,adjList1,vis,recStack);
                if(a) return true;
            }
            else{
                if(recStack[ele]==1) return true;
            }
        }
        recStack[node]=0;
        return false;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int counter=m;
        for(int i=0;i<group.size();i++){
            if(group[i]==-1){
                group[i]=m++;
            }
        }
        vector<vector<int>>adjList1(n);
        vector<int>indegree1(n,0);
        vector<int>outdegree1(n,0);
        for(int i=0;i<beforeItems.size();i++){
            for(int j=0;j<beforeItems[i].size();j++){
                int after=i;
                int before=beforeItems[i][j];
                outdegree1[before]++;
                indegree1[after]++;
                adjList1[before].push_back(after);
            }
        }

        queue<int>q;
        for(int i=0;i<indegree1.size();i++){
            if(indegree1[i]==0){
                q.push(i);
            }
        }

        vector<int>itemsSequence;
        vector<int>vis(n,0);
        vector<int>recStack(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            bool hasCycleOutput=hasCycle(i,adjList1,vis,recStack);
            if(hasCycleOutput) return {};
        }

        while(!q.empty()){
            int item=q.front();
            q.pop();
            itemsSequence.push_back(item);
            for(int neighbor:adjList1[item]){
                indegree1[neighbor]--;
                if(indegree1[neighbor]==0) q.push(neighbor);
            }
        }

       set<pair<int,int>>st;
       vector<vector<int>>adjList2(m);
       vector<int>indegree2(m,0);

       for(int i=0;i<beforeItems.size();i++){
         for(int j=0;j<beforeItems[i].size();j++){
            int after=i;
            int before=beforeItems[i][j];

            int beforeGroup=group[before];
            int afterGroup=group[after];

            if(beforeGroup==afterGroup) continue;

            if (st.find({beforeGroup,afterGroup}) != st.end()) continue;

            st.insert({beforeGroup,afterGroup});

            adjList2[beforeGroup].push_back(afterGroup);
            indegree2[afterGroup]++;


         }
       }

       vector<int>vis2(m,0);
       vector<int>recStack2(m,0);

       for(int i=0;i<m;i++){
            if(vis2[i]) continue;
            bool hasCycleOutput=hasCycle(i,adjList2,vis2,recStack2);
            if(hasCycleOutput) return {};
        }

        for(int i=0;i<indegree2.size();i++){
            if(indegree2[i]==0){
                q.push(i);
            }
        }

        vector<int>groupsSequence;
         while(!q.empty()){
            int item=q.front();
            q.pop();
            groupsSequence.push_back(item);
            for(int neighbor:adjList2[item]){
                indegree2[neighbor]--;
                if(indegree2[neighbor]==0) q.push(neighbor);
            }
        }

        vector<int>ans;

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<itemsSequence.size();i++){
            int item=itemsSequence[i];
            int itemGroup=group[item];
            mp[itemGroup].push_back(item);
        }

        for(int i=0;i<groupsSequence.size();i++){
            for(auto ele:mp[groupsSequence[i]]){
                ans.push_back(ele);
            }
        }





     return ans;;
    }
};