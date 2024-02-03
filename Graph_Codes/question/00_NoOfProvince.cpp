class Solution {
private:
    void dfs(int node,vector<int>adjls[],int vis[]){
        vis[node]=1;
        for(auto it:adjls[node]){
            if(!vis[it]){
                dfs(it,adjls,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int k =v;
        vector<int> adjls[v];
        for(int i =0;i<v;i++){
            for(int j =0;j<v;j++){
                if (isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }

            }
        }
        int vis[v];
        fill(vis, vis + v, 0);
        int count =0;
        for(int i =0;i<v;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjls,vis);
            }
        }
        return count;
    }
};