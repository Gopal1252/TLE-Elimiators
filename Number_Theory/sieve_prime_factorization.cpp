#include<bits/stdc++.h>
using namespace std;

//First we make the spf array (smallest prime factor array wherein we save the smallest prime factor of each number using sieve)
//Then we calculate the prime factorization of each number (TC: O(log(n)))

const int N = 1e6+10;
int spf[N];//smallest prime factor array

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //First mark the spf[i] = i for each number
    //whenever we encounter any i such that spf[i] = i, then we mark the spf of all it's multiples = i (only if it already doesn't have a smallest prime factor)

    for(int i=2;i<N;i++){
        spf[i] = i;
    }
    for(int i=2;i*i<N;i++){
        if(spf[i] != i) continue; //means i is not a prime number
        for(int j=i*i;j<N;j+=i){
            if(spf[j] == j){
                spf[j] = i;
            }
        }
    }

    vector<int> prime_factors;

    int x;//want to find the prime factorization of x

    //tc: O(log(x)) {approx}
    while(x>1){
        int prime_factor = spf[x];
        while(x%prime_factor == 0){
            x /= prime_factor;
            prime_factors.push_back(prime_factor);//storing exact prime factorization
        }
    }


    //tc: O(log(x)) {approx}
    while(x>1){
        int prime_factor = spf[x];
        prime_factors.push_back(prime_factor);//storing each prime factor only once
        while(x%prime_factor == 0){
            x /= prime_factor;
        }
    }



    return 0;
}