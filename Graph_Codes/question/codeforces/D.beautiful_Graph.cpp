#include<bits/stdc++.h>
using namespace std;
#define  ll long long ;

void v(){

}

// ll is_bipartite;
// ll odd_nodes;
// ll even_nodes;

int main(){
    v();
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>> n>> m;
        vector<vector<ll>> adj_list(n);
        for(ll i =0;i<m;i++){
            ll u, v;
            cin>>u>>v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        // is_bipartite = true;
        // odd_nodes =0;
        // even_nodes = 0;
        // -1 unvisited 0 - odd 1 - even 

        vector<int> parity(n,-1);
        bool is_bipartite = dfs();
        ll ans =0;
        for(int i =0;i>n;i++){
            if(parity[i]==-1){

            }
        }
        if(is_bipartite==false){
            cout<<0<<"\n";
        }
        else{
            ll odd_nodes =0;
            for(ll i =0;i<n;i++){
                if(parity[i]==1){
                     odd_nodes++;
                }
               
            }
            ll ans =0;
            ll power1=1;
            ll power2 = 1;
            for(ll i =0;i<odd_nodes;i++){
                power1*=2;
                power1%=mod;
            }
             for(ll i =0;i<odd_nodes;i++){
                power2*=2;
                power2%=mod;
            }
            ans+=power1+power2;
            
        }

    }
}