#include <bits/stdc++.h>
using namespace std;
#define int long long
int weight[600], parent[600];

struct edge{
    int x, y, w;
    bool operator<(edge &oth) const {
        return w<oth.w;
    }
};

int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void unite(int x, int y){
    int a = find(x), b = find(y);
    if(a == b) return;

    if(weight[a]>weight[b]) swap(a,b);
    weight[b]+=weight[a];
    parent[a] = b;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin>>n>>m;
    vector<edge> arr(m);
    for(auto &el: arr) cin>>el.x>>el.y>>el.w;

    sort(arr.begin(),arr.end());

    for(int i=0; i<n; i++) parent[i] = i;
    for(int i=0; i<n; i++) weight[i] = 1;

    int tam = 0;
    vector<edge> mst(m);
    for(int i=0; i<m; i++)
        if(find(arr[i].x) != find(arr[i].y)){
            unite(arr[i].x,arr[i].y);
            mst[tam++] = arr[i];
        }

    int ans=0;
    for(int i=0; i<n; i++) ans+=mst[i].w;
    cout<<ans<<endl;
}