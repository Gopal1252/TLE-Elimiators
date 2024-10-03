#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

long long getHash(string s){//may pass by ref
    long long h = 0;
    for(char c : s){
        h = ((h*1LL*31) + 0LL + (c - 'a' + 1))%M;
    }
    return h;
}

void prefHash(){

    //Prefix Hashing
    //Say I have a string s whose prefix hash I want ot calculate
    string s;
    int n = s.size();
    vector<int> prefHash(n,0);
    int hsh = 0;
    for(int i=0;i<n;i++){
        hsh = (hsh*1LL*31 + (s[i]-'a'+1))%M;
        prefHash[i] = hsh;
    }

    //to get hash from index i to j
    int newHash = (prefHash[j] - ((i>0)?prefHash[i-1]*1LL*binExp(31,(j-(i-1))):0)%M +M)%M;

    // basically 
    // pref[j] - pref[i-1]*pow(31,j-(i-1));

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cout<<getHash("dbc");

    return 0;
}