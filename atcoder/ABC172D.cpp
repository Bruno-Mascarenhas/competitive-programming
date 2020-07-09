#include <bits/stdc++.h>
#define int long long
#define ss second
#define ff first
using namespace std;
const int M = 1000000007;

int mod(int x, int m = M){
    x %= m;
    return x < 0 ? x+m : x;
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans=0, j;
    cin>>n;

    for(int i=1; i<=n; i++){
        j = n/i;
        ans += j*(j+1)*i/2;
    }
    
    cout<<ans<<endl;
}