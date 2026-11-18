class Solution {
public:
class Node{
        public: vector<Node*>mp;
                bool endOfWord;
                Node(){
                    this->mp=vector<Node*>(26,NULL);
                    this->endOfWord=false;
                }
                
    };
    class Trie{
        public:
               Node* root;
               Trie(){
                   this->root=new Node();
               }
               
               void insertIntoTrie(string word){
                   Node* temp=root;
                   for(auto ch:word){
                       if(temp->mp[ch-'a']==NULL){
                           temp->mp[ch-'a']=new Node();
                           temp=temp->mp[ch-'a'];
                       }
                       else{
                           temp=temp->mp[ch-'a'];
                       }
                   }
                   temp->endOfWord=true;
               }
               
               void searchWord(vector<string>&ans,string &temp,Node* roo,vector<vector<char>>&board,int row,int col,vector<vector<int>>&vis){
                   if(row<0||row>=board.size()||col<0||col>=board[0].size()||vis[row][col]){
                       return;
                   }
                   if(roo->mp[board[row][col]-'a']==NULL){
                       return;
                   }
                   
                   temp=temp+board[row][col];
                   vis[row][col]=1;
                   
                   if(roo->mp[board[row][col]-'a']->endOfWord==true){
                       ans.push_back(temp);
                       roo->mp[board[row][col]-'a']->endOfWord=false;
                   }
                   searchWord(ans,temp,roo->mp[board[row][col]-'a'],board,row,col+1,vis);
                   searchWord(ans,temp,roo->mp[board[row][col]-'a'],board,row,col-1,vis);
                   searchWord(ans,temp,roo->mp[board[row][col]-'a'],board,row+1,col,vis);
                   searchWord(ans,temp,roo->mp[board[row][col]-'a'],board,row-1,col,vis);
                   
                   vis[row][col]=0;
                   temp.pop_back();

               }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        vector<string>ans;
        Trie trie;
        for(int i=0;i<words.size();i++){
            trie.insertIntoTrie(words[i]);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                string temp="";
                trie.searchWord(ans,temp,trie.root,board,i,j,vis);
            }
        }
        return ans;
    }
};