#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int par, vector<int>& level, int lev = 0){
    cout<<node<<" ";
    level[node] = lev;
    for(auto & it : adj[node]){
        if(it == par) continue;
        dfs(it,adj,node,level,lev+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    return 0;
}