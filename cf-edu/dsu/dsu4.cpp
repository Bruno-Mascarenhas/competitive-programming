#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5+100;
 
int sz[maxn], link[maxn];
 
int get(int x){
    return link[x] == x ? x : link[x] = get(link[x]);
}
 
void unite(int a, int b){
    a = get(a), b = get(b);

    if(a == b) return;
 
    if(sz[a] < sz[b]) swap(a, b);
 
    link[b] = a;
    sz[a] += sz[b];
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q, u, v;
    cin>>n>>m>>q;
 
    for(int i=0; i<=n; i++) link[i] = i, sz[i] = 1;

    map<pair<int,int>, bool> edges;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        edges[{u,v}] = 1;
        edges[{v,u}] = 1;
    }

    vector<tuple<int,int,int>> queries; // 0 = ask | 1 = join

    while(q--){
        string op; int tmp;
        cin>>op;
        tmp = (op == "cut");
        cin>>u>>v;
        edges[{u,v}] = 0;
        edges[{v,u}] = 0;
        queries.push_back({tmp, u, v});
    }

    reverse(queries.begin(), queries.end());

    for(auto x: edges)
        if(x.second)
            unite(x.first.first, x.first.second);
    
    vector<string> ans;
    for(auto query: queries){
        int op;
        tie(op, u, v) = query;

        if(!op){
            ans.push_back(get(u) == get(v)?"YES":"NO");
        } else {
            unite(u, v);
        }
    }

    reverse(ans.begin(), ans.end());
    for(string x: ans) cout<<x<<endl;
}