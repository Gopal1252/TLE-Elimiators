//Given an array, find the first -ve number in every subarray of size k.
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int &i : arr){
        cin>>i;
    }

    vector<int> ans;
    queue<int> qu;

    for(int i=0;i<k;i++){
        if(arr[i]<0){
            qu.push(i);
        }
    }
    int ind = qu.front();
    ans.push_back(arr[ind]);

    for(int i=1; i<=n-k; i++){
        int j = i + k - 1;
        if(arr[j]<0){
            qu.push(i);
        }
        if(qu.front() == i-1){
            qu.pop();
        }
        int ind = qu.front();
        ans.push_back(arr[ind]); 
    }

    return 0;
}