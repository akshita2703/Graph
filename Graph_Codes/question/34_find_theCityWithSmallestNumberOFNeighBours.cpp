class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];

        }
        for(int i =0;i<n;i++) {
            dist[i][i]=0;
        }
        // floyd Warshal
        for(int k =0;k<n;k++){
            for(int i =0;i<n;i++){
                for(int j =0;j<n;j++){
                    if(dist[i][k]==INT_MAX||dist[k][j]==INT_MAX)continue;
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int cntMax = n+1;
        int city = -1;
        for(int i =0;i<n;i++){
            int count =0;
            for(int j =0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(cntMax>=count){
                city = i;
                cntMax = min(cntMax,count);
            }
           
        }
        return city;
    }
};