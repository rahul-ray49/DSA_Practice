class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>peak(isWater.size(),vector<int>(isWater[0].size(),0));
        vector<vector<int>>vis(isWater.size(),vector<int>(isWater[0].size(),0));


        vector<int>dx={0,0,-1,1};
        vector<int>dy={-1,1,0,0};
        queue<pair<int,int>>q;

        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){

                if(isWater[i][j]==1){

                    peak[i][j]=0;

                    q.push({i,j});
                    
                    vis[i][j]=1;


                }
                    

            }
        }

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newRow=dx[i]+row;
                int newCol=dy[i]+col;
                if(newRow<isWater.size()&&newCol<isWater[0].size()&&!vis[newRow][newCol]){
                    peak[newRow][newCol]=peak[row][col]+1;
                    vis[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }

        return peak;

    }
};