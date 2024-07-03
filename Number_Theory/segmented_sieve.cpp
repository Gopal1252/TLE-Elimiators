#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> sieve(N+1);

void precomp(){
    for(int i = 2; i<=N; i++){
        sieve[i] = 1;
    }
    for(int i=2; i*i<=N; i++){
        if(sieve[i] == 0) continue;
        for(int j=i*i; j<=N; j+=i){
            sieve[j] = 0;
        }
    }

    int l,r;
    cin>>l>>r;

    int size = r - l + 1;

    vector<int> dummy(size);

    for(int i=0; i<size; i++){
        dummy[i] = 1;
    }

    //mark in the dummy array all the non primes, rest will be primes
    //to mark the non primes, we wil just sort of doing the coordinate shifting
    for(int i=2;i*i<r;i++){//sinze r<1e9, so  root(r) will be less than 1e5 or 1e4
        if(sieve[i] == 1){
            //i is prime, so need to mark all the multiples of i = 0 in the dummy array
            
            //this is giving me the closest multiple of i<=l
            int initial = (l/i)*i;

            //if initial is less than l, then just take the next multiple
            if(initial < l){
                initial += i;
            }

            initial = max(i*i,initial);
            for(int j = initial - l; j<size; j+=i){
                dummy[j] = 0;
            }
        }
    }

    int cnt = 0;
    for(int i=0;i<size;i++){
        if(dummy[i]){
            cout<<l+i<<"\n";
            cnt++;
        }
    }
    cout<<cnt<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    precomp();

    return 0;
}