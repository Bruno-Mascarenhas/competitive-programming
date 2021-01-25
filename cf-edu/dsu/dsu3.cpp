#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int maxn = 3*1e5+100;
 
int sz[maxn], link[maxn], xp[maxn];
 
int get(int x){
    return link[x] == x ? x : get(link[x]);
}
 
void unite(int a, int b){
    a = get(a), b = get(b);

    if(a == b) return;

    if(sz[a] < sz[b]) swap(a, b);
 
    xp[b] -= xp[a];
    link[b] = a;
    sz[a] += sz[b];
}

int get_exp(int x){
    int ans = xp[x];
    while(x != link[x]){
        x = link[x];
        ans += xp[x];
    }
    return max(0LL,ans);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;
 
    for(int i=0; i<=n; i++) link[i] = i, sz[i] = 1, xp[i] = 0;
 
    while(q--){
        string op; int a, b;
        cin>>op;
 
        if(op == "join"){
            cin>>a>>b;
            unite(a, b);
        } else if(op == "add"){
            cin>>a>>b;
            xp[get(a)]+= b;
        } else{
            cin>>a;
            cout<<get_exp(a)<<endl;
        }
    }
}