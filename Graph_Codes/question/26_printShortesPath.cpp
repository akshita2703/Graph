class Solution {
  public:
  // out of 112 cases 111 were passed 
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //declare the vector of pair to store the node and it's weight
        
        //edgea = {{1, 2, 3}, {2, 3, 4}, {1, 3, 5}}
        // Vertex 1: (2, 3) (3, 5)
        // Vertex 2: (1, 3) (3, 4)
        // Vertex 3: (1, 5) (2, 4)

        vector<pair<int,int>> adj[n+1];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            
        }
        // priority_queue ({distance , node})
        priority_queue <pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX),parent(n+1);
        for(int i =1;i<=n;i++){
            parent[i]= i;
        }
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edw =  it.second;
                if(dis+edw<dist[adjNode]){
                    dist[adjNode]= dis+edw;
                    pq.push({dis+edw,adjNode});
                    parent[adjNode]= node;
                }
            }
        }
         if(dist[n] == INT_MAX) return {-1};
        vector<int> path;
        int node = n;
        path.push_back(dist[n]);
        while(parent[node]!=node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin()+1,path.end());
        return path;
    }
};