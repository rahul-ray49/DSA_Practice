class Solution {
public:
     class A{
        public:
           vector<int>rank;
           vector<int>parent;
            A(int n){
                rank.resize(n,1);
                parent.resize(n);
                for(int i=0;i<parent.size();i++){
                    parent[i]=i;
                }
            }

            int findParent(int x){
                if(parent[x]==x) return x;
                return parent[x]=findParent(parent[x]);
            }

            bool Union(int a,int b){
                int parA=findParent(a);
                int parB=findParent(b);
                
                if(parA==parB) return true;

                if(rank[parA]>rank[parB]){
                    parent[parB]=parA;
                    return false;
                }
                if(rank[parB]>rank[parA]){
                    parent[parA]=parB;
                    return false;
                }
                if(rank[parA]==rank[parB]){
                    rank[parA]++;
                    parent[parB]=parA;
                    return false;
                }
                return false;
            }
     };

    int MSTValue(vector<vector<int>>&edges,int n){

        int mstVal=0;

        A* obj= new A(n);


        for(int i=0;i<edges.size();i++){
            int node1=edges[i][0];
            int node2=edges[i][1];
            int wt=edges[i][2];

            int par1=obj->findParent(node1);
            int par2=obj->findParent(node2);

            if(par1==par2){
                continue;
            }

            mstVal+=wt;
            obj->Union(node1,node2);    
        }
        delete obj;
        return mstVal;

    }

    int MSTValue2(vector<vector<int>>&edges,int n,int skipIdx){

        int mstVal=0;
        A* obj=new A(n);

        for(int i=0;i<edges.size();i++){
            int node1=edges[i][0];
            int node2=edges[i][1];
            int wt=edges[i][2];
            int idx=edges[i][3];

            if(idx==skipIdx) continue;

            int par1=obj->findParent(node1);
            int par2=obj->findParent(node2);

            if(par1==par2){
                continue;
            }

            mstVal+=wt;
            obj->Union(node1,node2);    
        }

        set<int>s;
        for(int i=0;i<obj->parent.size();i++){
            s.insert(obj->findParent(i));
        }
        delete obj;
        if(s.size()>1) return INT_MAX;
        return mstVal;

    }

    int MSTValue3(vector<vector<int>>&edges,int n,int forceIdx){

        int mstVal=0;
        A* obj=new A(n);

        for(int i=0;i<edges.size();i++){
            if(edges[i][3]==forceIdx){
                obj->Union(edges[i][0],edges[i][1]);
                mstVal+=edges[i][2];
            }
        }

        for(int i=0;i<edges.size();i++){
            int node1=edges[i][0];
            int node2=edges[i][1];
            int wt=edges[i][2];
            int idx=edges[i][3];

            int par1=obj->findParent(node1);
            int par2=obj->findParent(node2);

            if(par1==par2){
                continue;
            }

            mstVal+=wt;
            obj->Union(node1,node2);    
        }

        delete obj;

        return mstVal;

    }



    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
       for(int i=0;i<edges.size();i++){
        edges[i].push_back(i);
       }
       sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        int MSTVALUE=MSTValue(edges,n);

        vector<int>critical;
        vector<int>pseudo;

        for(int i=0;i<edges.size();i++){
            int val=MSTValue2(edges,n,edges[i][3]);
            int val2=MSTValue3(edges,n,edges[i][3]);

            if(val>MSTVALUE){
                critical.push_back(edges[i][3]);
            }
            else{
                if(val2==MSTVALUE){
                    pseudo.push_back(edges[i][3]);
                }

            }
        }

        vector<vector<int>>ans;
        ans.push_back(critical);
        ans.push_back(pseudo);
        return ans;

    }
};