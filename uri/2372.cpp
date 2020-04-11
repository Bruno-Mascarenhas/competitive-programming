#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n,vector<int>(n,INF));

    for(int i=0; i<m; i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x][y] = w;
        adj[y][x] = w;
    }

    for(int k=0; k<n;k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);

    int ans = INF, to;

    for(int i=0; i<n; i++){
        to = 0;
        for(int j=0; j<n; j++)
            if(adj[i][j]!=INF) to = max(to,adj[i][j]);
        ans = min(to,ans);
    }

    cout<<ans<<endl;
}