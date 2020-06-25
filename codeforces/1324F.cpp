#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

vector<vector<int>> graph;
vector<int> dp,ans,arr;

int dfs(int u, int p = -1){
    dp[u] = arr[u];

    for(int to: graph[u]){
        if(p == to) continue;

        int tmp = dfs(to,u);

        dp[u] += max(0LL,tmp);
    }

    return dp[u];
}

void reroot(int u, int p = -1){
    ans[u] = dp[u];

    for(int to: graph[u]){
        if(p == to) continue;

        dp[u] -= max(0LL,dp[to]);
        dp[to] += max(0LL,dp[u]);

        reroot(to,u);

        dp[to] -= max(0LL,dp[u]);
        dp[u] += max(0LL,dp[to]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, u, v;
    cin>>n;
    arr.resize(n);    ans.resize(n);    dp.resize(n);    graph.assign(n,vector<int>());

    for(int &x: arr){
        cin>>x;
        if(!x) x--;
    }

    for(int i=1; i<n; i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0);
    reroot(0);

    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}