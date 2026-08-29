class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        vector<int>ans(arr.size());
        ans[arr.size()-1]=-1;
        stack<int>st;
        st.push(arr[arr.size()-1]);
        for(int i=arr.size()-2;i>=0;i--){
            int currEle=arr[i];
            if(st.empty()){
                ans[i]=-1;
                st.push(arr[i]);
                continue;
            }
            if(!st.empty()&&currEle<st.top()){
                ans[i]=st.top();
                st.push(arr[i]);
            }
            else{
                while(!st.empty()&&st.top()<=currEle){
                    st.pop();
                }
                if(st.empty()){
                    ans[i]=-1;
                    st.push(arr[i]);
                    
                }
                else{
                    ans[i]=st.top();
                    st.push(arr[i]);
                }
            }
        }
        return ans;
   
    }
};