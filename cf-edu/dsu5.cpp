#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5+100;
 
int sz[maxn], link[maxn], ans[maxn];
 
int get(int x){
    return link[x] == x ? x : link[x] = get(link[x]);
}
 
void unite(int a, int b){
    a = get(a), b = get(b);

    if(a == b) return;
 
    if(sz[a] < sz[b]) swap(a, b);
 
    link[b] = a;
    sz[a] += sz[b];
    //ans[b] = time;
}

void unite(int a, int b, int time){
    a = get(a), b = get(b);

    if(a == b) return;
 
    if(sz[a] < sz[b]) swap(a, b);
 
    link[b] = a;
    sz[a] += sz[b];
    ans[a] = time;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, u, v;
    cin>>n>>q;
 
    for(int i=0; i<=n; i++) link[i] = i, sz[i] = 1, ans[i] = -1;

    map<pair<int,int>, bool> edges;
    for(int i=1; i<=n; i++){
        cin>>u>>v;
        if(u!=-1){
            edges[{i,u}] = 1;
            edges[{u,i}] = 1;
        }
        if(v!=-1){
            edges[{i,v}] = 1;
            edges[{v,i}] = 1;
        }
    }

    vector<pair<int,int>> queries;

    for(int i=0; i<q; i++){
        cin>>u>>v;
        edges[{u,v}] = 0;
        edges[{v,u}] = 0;
        queries.push_back({u, v});
    }

    reverse(queries.begin(), queries.end());

    for(auto x: edges)
        if(x.second)
            unite(x.first.first, x.first.second);
    
    
    for(auto x: queries){
        u = x.first, v = x.second;

        unite(u, v, q--);
    }

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<endl;

}