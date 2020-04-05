#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
#define MAXN 101010 
#define MAXL 18

vector<vector<pii>> graph;
vector<int> parent, lvl, dist;
int ancestor[MAXN][MAXL];
int n, q;

void dfs(int node){
    for(pii to: graph[node]){
        int v = to.first, wth = to.second;
        if(parent[v]==-1){
            parent[v] = node;
            lvl[v] = lvl[node]+1;
            dist[v] = dist[node]+wth;
            dfs(v);
        }
    }
}

int LCA(int u, int v){
    if(lvl[u] < lvl[v])
        swap(u,v);

    for(int i=MAXL-1; i>=0; i--)
        if(lvl[u] - (1<<i) >= lvl[v])
            u = ancestor[u][i];

    if(u == v) return u;

    for(int i=MAXL-1; i>=0; i--)
        if(ancestor[u][i]!=-1 && ancestor[u][i] != ancestor[v][i]){
            u = ancestor[u][i];
            v = ancestor[v][i];
        }

    return parent[u];
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n && n){
        int v,w;
        graph.assign(n,vector<pii>());
        parent.assign(n,-1), dist.assign(n,0), lvl.assign(n,-1);
        memset(ancestor,-1,sizeof(ancestor));
        
        for(int i=1; i<=n-1; i++){
            cin>>v>>w;
            graph[min(i,v)].push_back({max(i,v),w});
        }

        lvl[0] = parent[0] = 0;
        dfs(0);

        for(int i=0; i<n; i++) ancestor[i][0] = parent[i];

        for(int j=1; j<MAXL; j++)
            for(int i=0; i<n; i++)
                if(ancestor[i][j-1] != -1) ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
        
        cin>>q;

        int a,b,ant;

        for(int i=0; i<q; i++){
            cin>>a>>b;
            ant = LCA(a,b);
            cout<<(i?" ":"")<<dist[a] + dist[b] - 2*dist[ant]; 
        }
        cout<<endl;
    }
}