class Solution {
public:
    int findParent(vector<int>&parent,int x){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent,parent[x]);
    }
    bool Union(vector<int>&parent,vector<int>&rank,int a,int b){
        int parA=findParent(parent,a);
        int parB=findParent(parent,b);

        if(parA==parB){
            return true;
        }
        if(rank[parA]==rank[parB]){
           parent[parB]=parA;
           rank[parA]++;
           return false;
        }
        if(rank[parA]>rank[parB]){
           parent[parB]=parA;
           return false;
        }
        if(rank[parB]>rank[parA]){
           parent[parA]=parB;
           return false;
        }
        return false;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool>ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int idx=0;
        vector<int>parent(n);
        vector<int>rank(n,1);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }

        for(int i=0;i<queries.size();i++){

            int wt=queries[i][2];
            int node1=queries[i][0];
            int node2=queries[i][1];
            int index=queries[i][3];

            while(idx<edgeList.size()&&edgeList[idx][2]<wt){
                Union(parent,rank,edgeList[idx][0],edgeList[idx][1]);
                ++idx;
            }

            int parNode1=findParent(parent,node1);
            int parNode2=findParent(parent,node2);

            ans[index]=(parNode1==parNode2);

        }
        return ans;
    }
};