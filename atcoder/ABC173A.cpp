#include <bits/stdc++.h>
#define ll long long
using namespace std;


signed main(){
    int n, ans; cin>>n;
    if(n <= 1000) ans = 1000 - n;
    else ans = 1000*((n+999)/1000) - n;
    cout<<ans<<endl;
}