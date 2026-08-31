class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),INT_MIN));
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==1){
            q.push({health-1,{0,0}});
            dp[0][0]=health-1;
        }
        else{
            q.push({health,{0,0}});
            dp[0][0]=health;
        }

        vector<int> dx = {-1, 1, 0, 0}; 
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty()){
           int row=q.front().second.first;
           int col=q.front().second.second;
           int heal=q.front().first;
           q.pop();

           if(heal>=1&&row==grid.size()-1&&col==grid[0].size()-1) return true;

           for (int i = 0; i < 4; i++) {
                int nx = row + dx[i];
                int ny = col + dy[i];

                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
                    int a=grid[nx][ny];
                    int h= (a==1) ? heal -1 : heal;
                    if(dp[nx][ny]<h){
                        dp[nx][ny]=h;
                        q.push({dp[nx][ny],{nx,ny}});
                    }
                }
            }

        }
        return false;
    }
};