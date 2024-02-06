 // rotten orange can rotten its neighbouring orange in 1 unit of time . so we have to find the time in which all the fresh orange will be rotten .
// https://leetcode.com/problems/rotting-oranges/

 class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //{{r,c},time}
        queue<pair<pair<int,int>,int>>q;
        int vis[n][m];
        int countF=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) countF++;
            }
        }
        int tm =0;
        int drow[]= {-1,0,1,0};
        int dcol[]= {0,1,0,-1};
        int count =0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            tm = max(tm,time);
            q.pop();  
            for(int i =0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                vis[nrow][ncol]!= 2 && grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol] = 2;
                    count++;
                }
            }   
        }
        // for(int i =0;i<n;i++){
        //     for(int j =0;j<m;j++){
        //         if(vis[i][j]!=2 && grid[i][j]==1){
        //             return -1;
        //         }
        //     }
        // }
        if(count!=countF)return -1;
        return tm;
        
    }
};