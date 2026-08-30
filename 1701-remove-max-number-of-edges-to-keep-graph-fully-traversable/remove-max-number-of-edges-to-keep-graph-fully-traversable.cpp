class Solution {
public:
    int findparent(vector<int>&parent,int x){
        if(parent[x]==x){
            return x;
        }

        return parent[x]=findparent(parent,parent[x]);
    }
    bool Union(vector<int>&parent,vector<int>&rank,int a,int b){
        int parA=findparent(parent,a);
        int parB=findparent(parent,b);
        if(parA==parB){
            return true;
        }
        if(rank[parA]==rank[parB]){
            parent[parB]=parA;
            rank[parA]++;
            return false;
        }
        if(rank[parA]<rank[parB]){
            parent[parA]=parB;
            return false;
        }
        if(rank[parB]<rank[parA]){
            parent[parB]=parA;
            return false;
        }
        return false;
        
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>parent1(n);
        vector<int>rank1(n,0);
        vector<int>parent2(n);
        vector<int>rank2(n,0);
        for(int i=0;i<parent1.size();i++){
            parent1[i]=i;
        }
        for(int i=0;i<parent2.size();i++){
            parent2[i]=i;
        }

        int count=0;
        
        for(int i=0;i<edges.size();i++){
            int type=edges[i][0];
            if(type!=3) continue;
             int u=edges[i][1]-1;
            int v=edges[i][2]-1;
            bool a=Union(parent1,rank1,u,v);
            bool b=Union(parent2,rank2,u,v);
            if(a&&b){
               ++count;
            }
        }

        for(int i=0;i<edges.size();i++){
            int type=edges[i][0];
            if(type==2||type==3) continue;
            int u=edges[i][1]-1;
            int v=edges[i][2]-1;

            if(Union(parent1,rank1,u,v)){
                ++count;
            }
        }

        for(int i=0;i<edges.size();i++){
            int type=edges[i][0];
            if(type==1||type==3) continue;
            int u=edges[i][1]-1;
            int v=edges[i][2]-1;

            if(Union(parent2,rank2,u,v)){
                ++count;
            }
        }

        

        int count1=0;
        int count2=0;
        for(int i=0;i<parent1.size();i++){
            if(parent1[i]==i) ++count1;
        }
        for(int i=0;i<parent2.size();i++){
            if(parent2[i]==i) ++count2;
        }
        if(count1>1||count2>1) return -1;
        return count;
        
    }
};