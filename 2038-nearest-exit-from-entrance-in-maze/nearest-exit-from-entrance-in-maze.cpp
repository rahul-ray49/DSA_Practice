class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int Erow=entrance[0];
        int Ecol=entrance[1];
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        vector<vector<int>>vis(maze.size(),vector<int>(maze[0].size(),0));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{Erow,Ecol}});
        vis[Erow][Ecol]=1;
        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int steps=q.front().first;
            q.pop();
            if((row!=Erow||col!=Ecol)&&(row==0||row==maze.size()-1||col==0||col==maze[0].size()-1)) return steps;
            for(int i = 0; i < 4; i++){
                int newx = row + dx[i];
                int newy = col + dy[i];
                if(newx >= 0 && newx < maze.size() && newy >= 0 && newy < maze[0].size() && !vis[newx][newy] && maze[newx][newy]=='.'){
                 vis[newx][newy]=1;
                 q.push({steps+1,{newx,newy}});
                }
            }

        }
        return -1;

    }
};