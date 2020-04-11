#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 50010
#define MAXL 17

vector<vector<int>> graph;
vector<int> lvl, parent, par, card;
int ancestor[MAXN][MAXL];

void dfs(int u){
    for(int to: graph[u])
        if(lvl[to] == -1){
            parent[to] = u;
            lvl[to] = lvl[u]+1;
            dfs(to);
        }
}

int lca(int u, int v){
    if(lvl[u] < lvl[v]) swap(u,v);

    for(int i=MAXL-1; i>=0; i--)
        if(lvl[u] - (1<<i) >= lvl[v])
            u = ancestor[u][i];
    
    if(u == v) return u;

    for(int i=MAXL-1; i>=0; i--)
        if(ancestor[u][i] != -1 && ancestor[u][i] != ancestor[v][i]){
            u = ancestor[u][i];
            v = ancestor[v][i];
        }

    return parent[u];
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, x, u, v;
    cin>>n;
    lvl.assign(n,-1), parent.assign(n,-1), par.assign(n,0), graph.assign(n,vector<int>()), card.assign(n,-1);
    memset(ancestor, -1, sizeof(ancestor));

    for(int i=0; i<n; i++){
        cin>>x;
        x--;
        if(card[x]!=-1) {
            par[i] = card[x];
            par[card[x]] = i;
        }
        card[x] = i;
    }

    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    lvl[0] = 0;
    dfs(0);

    for(int i=0; i<n; i++) ancestor[i][0] = parent[i];

    for(int j=1; j<MAXL; j++)
        for(int i=0; i<n; i++)
            if(ancestor[i][j-1]!=-1) ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];

    int ans=0;
    for(int i=0; i<n; i++)
        ans+= lvl[i] + lvl[par[i]] - 2*lvl[lca(i,par[i])];

    cout<<ans/2LL<<endl;
}