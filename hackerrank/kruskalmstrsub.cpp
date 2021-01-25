#include <bits/stdc++.h>
using namespace std; 

int link[3030], sz[3030];

int find(int x){
    return link[x] == x ? x : link[x] = find(link[x]);
}

void unite(int a, int b){
    a = find(a), b = find(b);

    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}

int main(){
    vector<tuple<int,int,int>> edges;
    int n, m;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        sz[i] = 1; link[i] = i;
    }

    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }

    sort(edges.begin(), edges.end());

    vector<tuple<int,int,int>> mst;

    for(auto node: edges){
        int a, b, w;
        tie(w,a,b) = node;
        if(find(a) != find(b)){
            unite(a, b);
            mst.push_back({w,a,b});
        }
    }

    int ans = 0;
    for(auto node: mst){
        int w;
        tie(w,ignore,ignore) = node;
        ans += w;
    }

    cout<<ans<<endl;
}