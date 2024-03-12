
// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int row ,int col,vector<vector<char>>& grid, vector<vector<int>>&vis){
        vis[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();
        int dr[]={-1,0,1,0,-1,-1,1,1};
        int dc[]={0,1,0,-1,1,-1,-1,1};
        for(int i =0;i<8;i++){
            int nr = row+dr[i];
            int nc = col+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1'&&vis[nr][nc]==0){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int row =0;row<n;row++){
            for(int col =0;col<m;col++){
                if(grid[row][col]=='1' && vis[row][col]==0){
                    ans++;
                    dfs(row,col,grid,vis);
                
                }
            
            }
        }
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends