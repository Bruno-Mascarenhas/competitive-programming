#include <bits/stdc++.h>
using namespace std;
#define int long long

double frac(int n, double qtd){
    if(n == 0) return qtd;
    double ans = qtd+6;
    return frac(n-1, 1.0/ans);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    cout<<fixed<<setprecision(10)<<3 + frac(n,0)<<endl;    
}