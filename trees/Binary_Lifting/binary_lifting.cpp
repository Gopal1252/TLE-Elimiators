#include<bits/stdc++.h>
using namespace std;

/*
Print kth parent of a node (query based question q<=1e5 and n<=1e5)
*/

int getParent(int node, int k, vector<vector<int>>& dp){
    int cnt = 0;//cnt represents power of 2 {(2^cnt)th parent} {sir --> cnt is the bit number}
    while(k){
        if(k&1){
            node = dp[node][cnt];
        }
        cnt++;
        k>>=1;
    }
    return node;
}

void dfs(int node, int par, vector<int> adj[], vector<vector<int>>& dp){

    //base case {at each node, rest of the dp array for this node will be calculated using this base case only}
    dp[node][0] = par;
    for(int i=1;i<=16;i++){
        dp[node][i] = dp[dp[node][i-1]][i-1];
    }

    for(auto &it : adj[node]){
        if(it == par) continue;
        dfs(it,node,adj,dp);
    }
}

void solve(){
    int n;
    cin>>n;

    vector<int> adj[n+1];
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<vector<int>> dp(n+1,vector<int>(17,0));//dp[i][j] stores the 2^jth parent of the ith node {1e5 <2^17}
    dfs(1,0,adj,dp);

    int q;
    cin>>q;

    while(q--){
        int node, k; //want the kth parent of node
        cin>>node>>k;

        cout<<getParent(node,k,dp)<<"\n";

    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    return 0;
}