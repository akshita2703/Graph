
// flood fill basically ek 2d matrix given h or starting row and starting col is also given or woh box hmra inicolor value store krta h 
//  1 1 1
//  2 2 0
// (2) 2 2
// touched to 2 and is 2 will be coloured to (3) ---> new colour


class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&ans,vector<vector<int>>&image , int color, int delRow[],int delCol[],int ini){
        ans[row][col]=color;
        int n = image.size();
        int m = image[0].size();
        for(int i =0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
             image[nrow][ncol] == ini && ans[nrow][ncol]!=color){
                 dfs(nrow, ncol, ans, image, color, delRow, delCol, ini);
             }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,color,delRow,delCol ,ini);
        return ans;

    }
};