#include<bits/stdc++.h>
using namespace std;

x
int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // if 3 and 7 belong to same component
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"same\n";
    }
    else{
        cout<<"Not same\n";
    }
    ds.unionBySize(3,7);
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"same\n";
    }
    else{
        cout<<"Not same\n";
    }

    return 0;
}