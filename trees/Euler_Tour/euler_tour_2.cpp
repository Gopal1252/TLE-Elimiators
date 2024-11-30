#include<bits/stdc++.h>
using namespace std;

vector<int> flat;//stores the flattended tree
int ind = 0;
map<int,pair<int,int>> mp;

void dfs(int node, int par, vector<int> adj[]){
    //entering the node
    mp[node].first = ind;
    flat.push_back(node);
    ind++;

    for(auto &it : adj[node]){
        if(it == par) continue;
        dfs(it,par,adj);
    }

    //exiting the node
    mp[node].second = ind;
    flat.push_back(node);
    ind++;
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

    dfs(1,0,adj);
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    return 0;
}