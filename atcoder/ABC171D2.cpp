#include <bits/stdc++.h>
#define ll long long
#define ss second
#define ff first
#define int long long
using namespace std;

int n, q, bi, ci, maxn = (int)1e6, tmp;
ll tot;
vector<int> freq(maxn,0);

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>tmp;
        freq[tmp] ++;
        tot+=(ll)tmp;
    }

    cin>>q;
    while(q--){
        cin>>bi>>ci;
        tmp = freq[bi];

        if(tmp){
            freq[bi] = 0;
            freq[ci] += tmp;

            tot += (ll)ci * (ll)tmp - ((ll)bi * (ll)tmp);
        }
        cout<<tot<<endl;
    }
}