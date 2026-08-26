class Solution {
public:
    bool hasUnique(string ans,string temp) {
       vector<int>freq(26,0);
       for(int i=0;i<ans.size();i++){
        freq[ans[i]-'a']++;
       }
       for(int i=0;i<temp.size();i++){
        if(freq[temp[i]-'a']!=0) return false;
        freq[temp[i]-'a']++;
       }
       return true;
    }
    int helper(string ans,vector<string>&arr,int idx){
        if(idx==arr.size()){
            return ans.size();
        }
        int include=0;
        if(hasUnique(ans,arr[idx])){
          include=helper(ans+arr[idx],arr,idx+1);

        }
        int exclude=0;
        
        exclude=helper(ans,arr,idx+1);
        return max(include,exclude);
        
    }
    int maxLength(vector<string>& arr) {
        string ans="";
        int idx=0;
        return helper(ans,arr,idx);
    }
};