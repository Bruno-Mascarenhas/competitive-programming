#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ff first
#define ss second
#define pb push_back
typedef pair<int,int> pii;

int dp[1010][11010], n, t, cont=1, w, v;
vector<pii> items[1010];
map<string,int> mapa;
string aux;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>t;
    for(int i=0; i<n; i++){
        cin>>w>>v>>aux;
        if(!mapa[aux])
            mapa[aux]=cont++;
        items[mapa[aux]].pb({w,v});
    }
    
    for(int i=1; i<=cont; i++)
        for(int j=0; j<=t; j++){
            dp[i][j] = dp[i-1][j];
            for(auto it: items[i])
                if(it.ff <= j)
                    dp[i][j] = max(dp[i][j],dp[i-1][j-it.ff]+it.ss);
            }

    cout<<dp[cont][t]<<endl;
}