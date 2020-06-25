#include <bits/stdc++.h>
#define ll long long
#define ss second
#define ff first
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, tot=0;

    cin>>n;

    vector<ll> arr(n);
    for(ll &x: arr){
        cin>>x;
        tot ^= x; 
    }

    for(ll x: arr) cout<<(x^tot)<<" ";
    cout<<endl;
}