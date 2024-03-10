

class DisjointSet{
    
public:
    vector<int> rank, parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);

        for(int i =0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByrank(int u ,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return ;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }

    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    

    }
};

class Solution {
public:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        // step 1
        for(int row=0;row<n;row++){
            for(int col =0;col<n;col++){
                if(grid[row][col]==0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int ind =0;ind<4;ind++){
                    int nr = row + dr[ind];
                    int nc = col + dc[ind];
                    if(isValid(nr,nc,n)&& grid[nr][nc]==1){
                        int nodeNo = row*n+col;
                        int adjnodeNo = nr*n+nc;
                        ds.unionBySize(nodeNo, adjnodeNo); // connect them

                    }

                }
            }

        }
        // step2 

        int mx =0;
        for(int row = 0;row<n;row++){
            for(int col =0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                set<int> components;
                for(int ind =0;ind<4;ind++){
                    int nr = row + dr[ind];
                    int nc = col + dc[ind];
                    if(isValid(nr,nc,n)){
                        if(grid[nr][nc]==1){
                            components.insert(ds.findUPar(nr*n+nc));
                        }
                    }
                }
                int sizeT =0;
                for(auto it : components){
                    sizeT+=ds.size[it];
                }
                mx = max(mx,sizeT+1);

            }

        }
        for(int cNo = 0;cNo<n*n;cNo++){
            mx = max(mx,ds.size[ds.findUPar(cNo)]);
        }
        return mx;

        
    }
};