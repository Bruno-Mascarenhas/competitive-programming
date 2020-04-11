#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> graph;
vector<int> dist,qtd,went,qtdwent;

void dfs(int parent=0, int level=0){
    qtd[level]++;
    if(went[parent]) qtdwent[level]++;

    for(int son: graph[parent])
        dfs(son,level+1);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin>>n>>m;    
    graph.assign(n+1,vector<int>());
    dist.assign(n+1,0);
    qtd.assign(n+1,0);
    qtdwent.assign(n+1,0);
    went.assign(n+1,0);

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        graph[x].push_back(i);
    }

    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        went[x]++;
    }

    dfs();

    for(int i=1; i<=n;i++)
        if(qtd[i] == 0) break;
        else cout<<fixed<<setprecision(2)<<100.0*qtdwent[i]/qtd[i]<<" ";
    cout<<endl;

}