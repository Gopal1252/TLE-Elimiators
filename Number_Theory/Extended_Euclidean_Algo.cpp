//gfg --> https://www.geeksforgeeks.org/problems/extended-euclidean-algorithm3848/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
#include<bits/stdc++.h>
using namespace std;

//normal gcd
int GCD(int a, int b){
    if(a == 0) return b;

    return GCD(b%a,a);
}

//initially gcd(a,b) = a*x + b*y

//this function returns gcd and along side calculates the value of x and y (therefor passed by reference)
int gcd(int a, int b, int& x, int &y){//purpose is to find x and y (pass by reference is important)
    //base case
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }

    int x1,y1;
    int g = gcd(b%a,a,x1,y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return g;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int x,y;
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b,x,y)<<" "<<x<<" "<<y;

    return 0;
}