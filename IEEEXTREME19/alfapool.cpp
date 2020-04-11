#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 3.1415926535897932384626
#define pb push_back
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

ll mx = (ll)1e9+7; const int sz = 1e5+1000;
ll mod(ll x){
    ll ans = x%mx;
    if(ans<0) ans+=mx;
    return ans;
}
ll arr[sz];

int main(){
    DESYNC;
    arr[0] = arr[1] = 2LL; arr[2] = 4LL;
    for(int i=3; i<sz; i++)
        arr[i] = mod(arr[i-2] + 2LL * arr[i-3]);
    int n,b;
    cin>>n;
    while(n--){
        cin>>b;
        if(b == 0) cout<<1<<endl;
        else cout<<arr[b-1]<<endl;
    }
}