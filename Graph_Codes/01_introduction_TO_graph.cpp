// How to store a graph in matrix? --undirected Graph
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n,m;
    int adj[n+1][n+1];
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1; // no need of this line in case of directed graph...
    }
}