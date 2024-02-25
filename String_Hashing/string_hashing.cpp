#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

long long getHash(string s){//may pass by ref
    long long h = 0;
    for(char c : s){
        h = (h*31 + (c - 'a' + 1))%M;
    }
    return h;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cout<<getHash("dbc");

    return 0;
}