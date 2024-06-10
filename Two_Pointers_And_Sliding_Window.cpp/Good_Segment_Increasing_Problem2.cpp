//Given an array of positive integers, find the length of the longest subarray number of distinct integers <=k
//soln1 --> binary search O(nlog(n))
//soln2 --> two pointer O(2n)
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans = 0, sum = 0, i = 0, j = 0;
    map<int,int> freq;

    while(j<n){
        freq[a[j]]++;

        while(i<=j && freq.size()>k){
            freq[a[i]]--;
            if(freq[a[i]] == 0){
                freq.erase(a[i]);
            }
            i++;
        }
        ans = max(ans, j-i+1);
        j++;
    }

    return 0;
}