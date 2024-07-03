#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll M = 1e9 + 7;

const ll N = 1e6 ; 
ll fact[N+1];
ll modInv[N+1];

//binary exponentiation
ll power(ll base, ll x){
    if(x<0) return 0;

    ll ans = 1;
    while(x){
        if(x%2 == 0){
            base = (base*base)%M;
            x = x/2;
        }
        else{
            ans = (ans * base)%M;
            x--;
        }
    }
    return ans;
}

//my code of binary exponentiaiton
ll binExp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b>>=1;
    }
    return ans;
}

//Way1 {Q = 1e7 might not pass} //OR use when N is large and Q is small

void precomp1(){ //TC :O(N)
    fact[0] = 1;
    for(ll i = 1; i<=N; i++){
        fact[i] = (fact[i-1] * i)%M;
    }
}

//each value of fact[n] will be in the range from 0 to 1e9+6
ll ncr1(ll n, ll r){
    if(n<0 || r<0 || r>n) return 0; //just for safety
    ll numo = fact[n];
    ll deno = (fact[r] * fact[n-r])%M;
    ll ans = (numo * power(deno,M - 2))%M;
    return ans;
    //tc:-> O(log(M)) 
}

//Way2 (a little better than Way1, can work for a little larger values of Q) {Q = 1e7 will pass} //use when N is small and Q is large

void precomp2(){ //TC :O(N * log(M))
    fact[0] = 1;
    modInv[0] = 1;//v.v.imp
    for(ll i = 1; i<=N; i++){
        fact[i] = (fact[i-1] * i)%M;
        modInv[i] = power(fact[i],M-2);
    }
}

ll ncr2(ll n, ll r){
    if(n<0 || r<0 || r>n) return 0; //just for safety
    ll numo = fact[n];
    ll invDeno = (modInv[r] * modInv[n-r])%M; // equivalent to 1/(fact[r] * fact[n-r])
    ll ans = (numo * invDeno)%M;
    return ans;
    //tc:-> O(1)
}


//TC (way1) --> O(N) + O(Q * log(mod)) 
//TC (way2) --> O(N * log(mod)) + O(Q)  //see notes to know why this is better {since now we can work with bigger values of Q without getting TLE}

//Way1 --> use when N is large
//Way2 --> use when Q is large


void solve(){
    int q;
    cin>>q;
    precomp2();
    while(q--){
        //calc ncr over here
        ll n,r;
        cin>>n>>r;
        cout<<ncr2(n,r)<<"\n";
    }

}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}