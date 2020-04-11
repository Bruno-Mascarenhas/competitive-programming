#include <bits/stdc++.h>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define ld long double
using namespace std;
const int maxn = 1e5+10;

int32_t main(){
    DESYNC;
    ld r,v, ds;
    int g, d;
    cin>>g>>d>>r; 
    if(d) ds = 1-(d/100);
    d ? v = r/ds : v = r;
    ld ans = (v * 1000) / g;
    cout<<fixed<<setprecision(12)<<ans<<endl;
}