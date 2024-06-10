//Given an array of positive integers, find the length of the smallest subarray with sum of elements with sum >= k
//soln1 --> binary search O(nlog(n))
//soln2 --> two pointer O(2n)
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+10;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans = INF, sum = 0, i = 0, j = 0;

    while(j<n){
        sum += a[j];

        while(i<=j && sum>=k){
            ans = min(ans,j-i+1);
            sum-=a[i];
            i++;
        }
        j++;
    }

    return 0;
}