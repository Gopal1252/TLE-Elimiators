#include<bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of workloads, split it among K workers, such that the maximum work any worker has 
to do is minimized. You can split the workload continuously only {i.e as subarrays only}
Eg: K = 3, A = [10,5,20,50,25,45,15]  ==> Ans = 75 
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k = 3;
    vector<int> a = {10,5,20,50,25,45,15};

    auto ok = [&](int m) -> bool {
        int cnt = 1;
        int sum = 0;
        for(int i : a){
            if(sum+i>m){
                cnt++;
                sum = i;
            }
            else{
                sum += i;
            }
        }
        return cnt <= k;
    };

    int ans = -1 ;

    int l = *max_element(a.begin(),a.end());
    int r = accumulate(a.begin(),a.end(),0);

    while(l <= r){
        int m = (l+r)/2;

        if(ok(m)){
            ans = m;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    cout<<ans<<"\n";


    return 0;
}