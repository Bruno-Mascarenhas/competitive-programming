#include <bits/stdc++.h>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define ld long double
using namespace std;
const int maxn = 1e5+10;

int32_t main(){
    DESYNC;
    ld g,d,r;
    cin>>g>>d>>r; 
    d = d/100;
    ld v = r/d;
    ld ans = (v * 1000) / g;
    cout<<ans<<endl;
}