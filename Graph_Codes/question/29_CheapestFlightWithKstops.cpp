//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ppr pair<int,pair<int,int>>

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
            
        }
        queue<ppr>q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto it = q.front();
            int stop = it.first;
            int node = it.second.first;
            int distance = it.second.second;
            q.pop();
            if(stop>K)continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgW = it.second;
                if(distance+edgW<dist[adjNode] && stop<=K){
                    dist[adjNode]= distance+edgW;
                    q.push({stop+1,{adjNode,distance+edgW}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends