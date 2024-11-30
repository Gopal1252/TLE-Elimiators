#include<bits/stdc++.h>
using namespace std;

vector<int> flat;//stores the flattended tree
map<int,int> mp;//stores the first index at which a node occurs in the flattened tree
int ind = 0;

void dfs(int node, int par, vector<int> adj[]){
    if(mp.find(node) == mp.end()){
        mp[node] = ind;
    }
    flat.push_back(node);
    ind++;

    for(auto &it : adj[node]){
        if(it == par) continue;
        dfs(it,par,adj);
        flat.push_back(node);
        ind++;
    }

}

void solve(){
    int n;
    cin>>n;

    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);


    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    return 0;
}