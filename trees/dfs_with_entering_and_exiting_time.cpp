#include<bits/stdc++.h>
using namespace std;

map<int,pair<int,int>> mp;
int t = 0;

//(I) doing two times t++, so that for the same node, we don't have the same entering and exiting time (think of the leaf node)
void dfs(int node, vector<int> adj[], int par){
    cout<<node<<" ";
    mp[node].first = t;
    t++;
    for(auto & it : adj[node]){
        if(it == par) continue;
        dfs(it,adj,node);
    }
    mp[node].second = t;
    t++;
}

void bfs(int root, vector<int> adj[]){
    queue<pair<int,int>> q;
    // {node,parent}
    q.push({root,-1});
    int level = 0;
    while(!q.empty()){
        int k = q.size();

        for(int i=0;i<k;i++){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            cout<<node<<" ";
            for(auto & it : adj[node]){
                if(it == parent) continue;
                q.push({it,node});
            }
        }
        level++;
    }
    cout<<level<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    return 0;
}