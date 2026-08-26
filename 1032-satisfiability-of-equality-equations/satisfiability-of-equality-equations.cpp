class Solution {
public:
    
    int findParent(vector<int>&parent,int x){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent,parent[x]);
    }

    bool unioning(vector<int>&parent,vector<int>&rank,int a,int b){
        int parA=findParent(parent,a);
        int parB=findParent(parent,b);
        if(parA==parB) return false;
        if(rank[parA]>rank[parB]){
            parent[parB]=parA;
        }
        else{
            if(rank[parA]==rank[parB]){
                parent[parB]=parA;
                rank[parA]++;
            }
            else{
                parent[parA]=parB;
                rank[parB]++;
            }
        }
        return true;
    }




    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        vector<int>rank(26,0);
        for(int i=0;i<equations.size();i++){
            string str=equations[i];
            if(str[1]== '=' && str[2]== '='){
                unioning(parent,rank,str[0]-'a',str[3]-'a');
            }
            
        }
        for(int i=0;i<equations.size();i++){
            string str=equations[i];
            if(str[1]== '=' && str[2]== '=') continue;
                int A=str[0]-'a';
                int B=str[3]-'a';
                int parA=findParent(parent,A);
                int parB=findParent(parent,B);
                if(parA==parB) return false;
        }
        return true;
    }
};