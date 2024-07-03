//used when r is very small or r is very close to n or when need to calc only once (and not giving tle)
//ex nc2, nc4,nc(n-2),nc(n-4) etc
#include<bits/stdc++.h>
using namespace std;

#define ll long long

//TC: O(min(r,n-r))
ll ncr(ll n, ll r){
    ll ans = 1;
    for(ll i=1;i<=min(r,n-r);i++){
        ans = (ans * (n-i+1))/i;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,r;
    cin>>n>>r;

    //calculating ncr

    //TC: O(min(r,n-r))
    ll ans = 1;
    for(ll i=1;i<=min(r,n-r);i++){
        ans = (ans * (n-i+1))/i;
    }

    cout<<ans<<"\n";

    return 0;
}