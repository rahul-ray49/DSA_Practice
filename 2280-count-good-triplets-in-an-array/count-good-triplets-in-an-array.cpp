class Solution {
public:

    void updateQuery(vector<int>&segTree,int index,int start,int end,int idx){
        if(index<start||index>end) return;
        if(start==end){
            segTree[idx]=1;
            return;
        }
        
        int mid=start+(end-start)/2;
        if(index<=mid){
            updateQuery(segTree,index,start,mid,2*idx+1);
        }
        else{
            updateQuery(segTree,index,mid+1,end,2*idx+2);
        }
        segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
    }

    int rangeQuery(vector<int>&segTree,int start,int end,int l,int r,int idx){
        if(end<l||start>r) return 0;
        if(start>=l&&end<=r) return segTree[idx];

        int mid=start+(end-start)/2;
        int a=rangeQuery(segTree,start,mid,l,r,2*idx+1);
        int b=rangeQuery(segTree,mid+1,end,l,r,2*idx+2);
        return a+b;
    }



    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans=0;
        vector<int>segTree(nums1.size()*4,0);
        int start=0;
        int end=nums1.size()-1;
        int idx=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        updateQuery(segTree,mp[nums1[0]],start,end,idx);
        for(int i=1;i<nums1.size();i++){
            long long index=mp[nums1[i]];
            int commonElementsOnLeftSide=rangeQuery(segTree,start,end,0,index,idx);
            updateQuery(segTree,index,start,end,idx);
            if(commonElementsOnLeftSide==0) continue;
            long long notCommonElementsOnLeftSide=(i-commonElementsOnLeftSide);
            long long  elements_After_index_in_nums2=nums2.size()-1-index;
            long long commonElementsOnRightSide=elements_After_index_in_nums2-notCommonElementsOnLeftSide;
           

            ans+=(commonElementsOnLeftSide*commonElementsOnRightSide);




        }
        return ans;
    }
};