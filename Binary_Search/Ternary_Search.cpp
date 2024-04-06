#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    auto f = [](double x) -> double{ //whatever unimodal function as per the question

    };

    const double EPS = 1e-9;
    double l = 0, r = 1e9;
    while(r-l>EPS){
        double m1 = l + (r-l)/3; // (2l+r)/3
        double m2 = r - (r-l)/3; // (l+2r)/3
        if(f(m1) < f(m2)) l = m1; //this is while finding the maxima, for minima, just do r = m2 here and l = m1 in the else positon
        else r = m2;
    }
    //do the output as per the question
    //can output l or r anyone, since eps is very small, so thery both are gonna be same
    cout<< fixed << setprecision(5);
    cout<<l; 
    cout<<f(l); 

    return 0;
}