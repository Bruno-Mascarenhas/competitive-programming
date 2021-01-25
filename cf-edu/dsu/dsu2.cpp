#include <bits/stdc++.h>
using namespace std;

const int maxn = 4*1e5+100;

int sz[maxn], link[maxn], mini[maxn], maxi[maxn];

int get(int x){
    return link[x] == x ? x : link[x] = get(link[x]);
}

void unite(int a, int b){
    a = get(a), b = get(b);

    if(a == b) return;

    if(sz[a] == sz[b] || sz[a] > sz[b]){
        maxi[a] = max(maxi[a], maxi[b]);
        mini[a] = min(mini[a], mini[b]);
        sz[a] += sz[b];
        link[b] = link[a];
    } else {
        maxi[b] = max(maxi[a], maxi[b]);
        mini[b] = min(mini[a], mini[b]);
        sz[b] += sz[a];
        link[a] = link[b];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;

    for(int i=1; i<=n; i++) link[i] = i, sz[i] = 1, mini[i] = i, maxi[i] = i;

    while(q--){
        string op; int a, b;
        cin>>op;

        if(op == "union"){
            cin>>a>>b;
            unite(a, b);
        }else{
            cin>>a;
            int v = get(a);
            cout<<mini[v]<<" "<<maxi[v]<<" "<<sz[v]<<endl;
        }
    }
}