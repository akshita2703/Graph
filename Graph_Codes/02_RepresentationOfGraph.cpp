// How to store a graph in list? --undirected Graph
#include<bits/stdc++.h>
using namespace std;

// 1 based indexing 
// 0
// 1 --> {2,3}
// 2 --> {1,4,5}
// 3 --> {1,4}
// 4 --> {3,2,5}
// 5 --> {2,4}
 // O(2E)

int main(){
    int n,m;
    cin>>n,m;
    vector<int> adj[n+1];
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // no need of this line in case of directed graph...
    }
    return 0;
}