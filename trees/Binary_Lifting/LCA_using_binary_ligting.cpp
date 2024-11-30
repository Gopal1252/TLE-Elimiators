#include<bits/stdc++.h>
using namespace std;

int getKPar(int node, int k, vector<vector<int>>& dp){
    int cnt = 0;
    while(k){
        if(k&1){
            node = dp[node][cnt];
        }
        cnt++;
        k>>=1;
    }
    return node;
}

void dfs(int node, int par, vector<int> adj[], vector<vector<int>>& dp, vector<int>& level, int l = 0){
    dp[node][0] = par;

    for(int i=1;i<=16;i++){
        dp[node][i] = dp[dp[node][i-1]][i-1];
    }

    level[node] = l;

    for(auto & it : adj[node]){
        if(it == par) continue;
        dfs(it,node,adj,dp,level,l+1);
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

    vector<vector<int>> dp(n+1,vector<int>(17,0));
    vector<int> level(n+1);//stores the level {level of root = 0}

    dfs(1,0,adj,dp,level,0);
 
    int q;
    cin>>q;

    while(q--){
        int a,b;
        cin>>a>>b;

        //Step1: first bring both at the same level

        //assuming a is at lower level, if not, just swap a and b
        if(level[a] > level[b]){
            swap(a,b);
        }

        //a is at a lower level than b
        int k = level[b] - level[a];

        //shift b by k level
        b = getKPar(b,k,dp);

        //now both at the same level
        
        //check if a = b, then it means one of them itself was the LCA (the one at the lower level)
        if(a == b){
            cout<<a<<"\n";
            continue;
        }

        //Step2: Move a and b to every unequal parent
        for(int i=16;i>=0;i--){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        cout<<dp[a][0]<<"\n";//or can do dp[b][0] since both a and b will be one level below LCA at the end
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    return 0;
}