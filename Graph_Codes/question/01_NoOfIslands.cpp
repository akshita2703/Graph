// I dont know why this code is not working 

// class Solution {
// private:
// void bfs(int row1 ,int col1 , vector<vector<int>>&vis,vector<vector<char>>& grid){
//         vis[row1][col1]=1;
//         queue<pair<int,int>> q;
//         q.push({row1,col1});
//         int n = grid.size();
//         int m = grid[0].size();
//         while(!q.empty()){
//             int row2 = q.front().first;
//             int col2 = q.front().second;
//             q.pop();
//             // traverse in the neighbours and mark them is its a land
//             for(int delrow =-1;delrow<=1;delrow++){
//                 for(int delcol =-1;delcol<=1;delcol++){
//                     int nrow = row2  + delrow;
//                     int ncol = col2 + delcol;
//                     if((nrow>=0 && nrow<n && ncol>=0 && ncol<m) && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
//                         vis[nrow][ncol]=1;
//                         q.push({nrow,ncol});
//                     }
//                 }
//             }
//         }

//     }
// public:
    
//     int numIslands(vector<vector<char>>& grid) {
//         int n =  grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n,vector<int>(m,0));
//         int count=0;
//         for(int row =0;row<n;row++){
//             for(int col =0;col<m;col++){
//                 if(vis[row][col]==0 && grid[row][col]=='1'){
//                     count++;
//                     bfs(row,col,vis,grid);
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
    void bfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int i,int j){
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<int>rItr={-1,0,1,0};
        vector<int>cItr={0,1,0,-1};
        q.push({i,j});
        while(!q.empty()){
            int ii=q.front().first;
            int jj=q.front().second;
            q.pop();
            for(int dir=0;dir<4;dir++){
                int nr=ii+rItr[dir];
                int nc=jj+cItr[dir];
                if(nr>=0 && nr<n  &&  nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};