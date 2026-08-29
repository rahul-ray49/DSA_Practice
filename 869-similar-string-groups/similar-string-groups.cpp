class Solution {
public:
    int findParent(int x,vector<int>&parent){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent[x],parent);
    }
    bool Union(vector<int>&parent,vector<int>&rank,int a,int b){
        int parA=findParent(a,parent);
        int parB=findParent(b,parent);
        if(parA==parB){
            return true;
        }
        if(rank[parA]>rank[parB]){
            parent[parB]=parA;
            return true;
        }
        if(rank[parB]>rank[parA]){
            parent[parA]=parB;
            return true;
        }
        if(rank[parA]==rank[parB]){
            rank[parA]++;
            parent[parB]=parA;
            return true;
        }
        return false;
    }

    bool checkSimilarity(string s1,string s2){
        int count=0;
        if(s1.size()!=s2.size()) return false;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) ++count;
        }
        if(count>2) return false;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        vector<int>parent(strs.size());
        vector<int>rank(strs.size(),0);
        for(int i=0;i<parent.size();i++) parent[i]=i;
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                string s1=strs[i];
                string s2=strs[j];
                if(!checkSimilarity(s1,s2)) continue;
                Union(parent,rank,i,j);
            }
        }

        int count=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i) ++count;
        }

        return count;



    }
};