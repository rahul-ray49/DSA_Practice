class Solution {
public:
void buildSegmentTree(vector<int>&baskets,int idx,int start,int end,vector<int>&segTree){
    if(start==end){
        segTree[idx]=start;
        return;
    }
    int mid=start+(end-start)/2;
    buildSegmentTree(baskets,2*idx+1,start,mid,segTree);
    buildSegmentTree(baskets,2*idx+2,mid+1,end,segTree);
    if(baskets[segTree[2*idx+1]]>=baskets[segTree[2*idx+2]]){
        segTree[idx]=segTree[2*idx+1];
    }
    else{
        segTree[idx]=segTree[2*idx+2];
    }
}
 
int maxRangeQuery(vector<int>&baskets,vector<int>&segTree,int start,int end,int l,int r,int idx){
    if(end<l||start>r) return -1;
    if(start>=l&&end<=r) return segTree[idx];
    int mid=start+(end-start)/2;
    int a=maxRangeQuery(baskets,segTree,start,mid,l,r,2*idx+1);
    int b=maxRangeQuery(baskets,segTree,mid+1,end,l,r,2*idx+2);
    if(a==-1) return b;
    if(b==-1) return a;
    if(baskets[a]>=baskets[b]) return a;
    return b;

}

void updateRangeQuery(vector<int>&segTree,int idx,int i,vector<int>&baskets,int start,int end){
    if(start==end&&start==i){
        segTree[idx]=-1;
        return;
    }
    if(i<start||i>end){
        return;
    }
    int mid=start+(end-start)/2;
    updateRangeQuery(segTree,2*idx+1,i,baskets,start,mid);
    updateRangeQuery(segTree,2*idx+2,i,baskets,mid+1,end);
    int a=segTree[2*idx+1];
    int b=segTree[2*idx+2];
    if(a==-1) {
        segTree[idx]=b;
        return;
    }
    if(b==-1){
        segTree[idx]=a;
        return;
    }
    if(baskets[segTree[2*idx+1]]>=baskets[segTree[2*idx+2]]){
        segTree[idx]=segTree[2*idx+1];
    }
    else{
        segTree[idx]=segTree[2*idx+2];
    }
    
}
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int>segTree(fruits.size()*4);
        int start=0;
        int end=fruits.size()-1;
        int idx=0;
        int count=0;
        buildSegmentTree(baskets,idx,start,end,segTree);
        for(int i=0;i<fruits.size();i++){
            int f=fruits[i];
            int si=0;
            int ei=fruits.size()-1;
            int ans=-1;
            while(si<=ei){
                int mid=si+(ei-si)/2;
                int index=maxRangeQuery(baskets,segTree,start,end,si,mid,idx);
                if(index!=-1&&baskets[index]>=f){
                    ans=index;
                    ei=mid-1;
                }
                else{
                    si=mid+1;
                }
            }
            if(ans!=-1){
                ++count;
                updateRangeQuery(segTree,idx,ans,baskets,start,end);
            }
        }
        return fruits.size()-count;
    }
};