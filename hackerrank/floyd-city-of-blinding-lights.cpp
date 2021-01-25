#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = INT_MAX-100;

vector<vector<int>> graph(500, vector<int> (500, inf));

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, u, v, w, q;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        graph[u][v] = w;
    }

    cin>>q;
    for(int k=0; k<=n; k++)
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                if(i == j) graph[i][j] = 0;
                else graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    
    while(q--){
        cin>>u>>v;
        cout<<(graph[u][v] == inf ? -1 : graph[u][v])<<endl;
    }
}