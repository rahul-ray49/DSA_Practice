class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int len=INT_MAX;
        int i=0;
        int j=0;
        int count=0;
        while(j<s.size()){
            if(s[j]=='1'){
                ++count;
            }
            if(count<k){
                ++j;
                continue;
            }
            else{
                while(i<=j&&count==k){
                       string str="";
                       for(int x=i;x<=j;x++){
                        str=str+s[x];
                       }
                       if(str.size()<len || (str<=ans&&str.size()==len)){
                        ans=str;
                        len=ans.size();
                       }
                       if(s[i]=='1') --count;
                       ++i;
                    
                }
                ++j;
            }
        }
        return ans;
    }
};