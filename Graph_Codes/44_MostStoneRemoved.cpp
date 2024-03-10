
class DisjointSet{
    vector<int> rank, parent,size;
public:
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
    void unionBySize(int u ,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n  = stones.size();
        int maxR =0;
        int maxC = 0;
        for(auto it : stones){
            maxR=max(maxR,it[0]);
            maxC=max(maxC,it[1]);
        }
        DisjointSet ds(maxR+maxC+1);
        unordered_map<int ,int> mp;
        for(auto it:stones){
            int NodeR = it[0];
            int NodeC = it[1]+maxR+1;
            ds.unionBySize(NodeR,NodeC);
            mp[NodeR] = 1;
            mp[NodeC] = 1;
        }
        int cnt=0;
        for(auto it : mp){
            if(ds.findUPar(it.first)==it.first){
                cnt++;
            }
        }

        return n - cnt;
        
    }
};