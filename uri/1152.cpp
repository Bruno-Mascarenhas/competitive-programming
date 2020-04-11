#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int maxn = 2e6;
int n, m, ans, tot, sz[maxn], link[maxn];
struct edge{
    int x,y,w;
};
bool cmp(edge a, edge b){
    return a.w < b.w;
}
int find(int x){
    return link[x] == x ? x : link[x] = find(link[x]);
}
void join(int a, int b){
    a = find(a); b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a]+=sz[b];
    link[b] = a;
}

edge edges[maxn], mst[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m && n+m>0){
        ans = tot = 0;
        for(int i=0; i<=n; i++){
            link[i] = i; sz[i] = 1;
        }
        for(int i=0; i<m; i++){
            cin>>edges[i].x>>edges[i].y>>edges[i].w;
            tot+=edges[i].w;
        }
        sort(edges,edges+m,cmp);
        int tam = 0;
        for(int i=0; i<m; i++)
            if(find(edges[i].x)!=edges[i].y){
                join(edges[i].x,edges[i].y);
                mst[tam++] = edges[i];
            }
        for(int i=0; i<n-1; i++)ans+=mst[i].w;
        cout<<tot-ans<<endl;
    }

    return 0;
}