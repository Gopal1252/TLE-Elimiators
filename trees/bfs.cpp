#include<bits/stdc++.h>
using namespace std;

void bfs(int root, vector<int> adj[]){
    queue<pair<int,int>> q;
    // {node,parent}
    q.push({root,-1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        cout<<node<<" ";
        for(auto & it : adj[node]){
            if(it == parent) continue;
            q.push({it,node});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    return 0;
}