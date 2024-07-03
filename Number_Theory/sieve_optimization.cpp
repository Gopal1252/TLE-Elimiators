#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> isPrime(N,1);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //normal TC: O(N*log(log(N))) {approx}
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<N;i++){
        if(isPrime[i]){
            for(int j=2*i;j<N;j+=i){
                isPrime[j] = 0;
            }
        }
    }

    //2 Optimizations:
    //1. Start inner loop from i*i
    //2. Run the outer loop till i*i<N (root N)


    //Sir still wrote the same TC --> O(N*log(log(N))) {approx}
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i*i<N;i++){
        if(isPrime[i]){
            for(int j=i*i;j<N;j+=i){
                isPrime[j] = 0;
            }
        }
    }


    return 0;
}