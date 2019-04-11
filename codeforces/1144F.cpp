#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bit(x,i) (x&(1<<i))
#define sz(x) ((int)((x).size()))
#define pi 3.1415926535897932384626
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define EPS 1e-9
#define INF 1e18
#define ALL(x) for(int i=0; i<x; i++)
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define m0(x) memset((x), 0, sizeof(x))
#define m1(x) memset((x), -1, sizeof(x))

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
typedef vector<pii> vii;

const int32_t maxn = 2e5+10;

int n,m,x,y,color[maxn]; vi g[maxn]; vii edges;
int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  while(m--){
    cin>>x>>y;
    x--;y--;
    g[x].pb(y);
    g[y].pb(x);
    edges.pb({x,y});
  }
  for(int i=0; i<n; i++)color[i] = -1;
  color[0] = 1; int f = 1;

  queue<int> fila; fila.push(0);
  while(!fila.empty()){
    int q = fila.front(); fila.pop();
    for(int to:g[q]){
      if(color[to] == -1){
        color[to] = 1-color[q];
        fila.push(to);
      }
      else if(color[to] == color[q]){f = 0; break;}
    }
  }
  if(!f) cout<<"NO\n";
  else{
    cout<<"YES\n";
    for(auto it: edges)      cout<<color[it.ff];
    cout<<endl;
  }
}