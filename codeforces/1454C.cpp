#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
#define bit(x,i) (x&(1<<i))
#define pi 3.1415926535897932384626
#define pb push_back
#define pf push_front
#define mt make_tuple
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define EPS 1e-9
#define INF 1e18
#define for0(x) for(int i=0; i<x; i++)
#define ALL(x) a.begin(),a.end()
#define fori(a,b,c) for(int a=b; a<c; a++)
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define m0(x) memset((x), 0, sizeof(x))
#define m1(x) memset((x), -1, sizeof(x))

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

inline int mod(int n){ return (n%1000000007); }
//Compilation flags // g++ -std=c++17 -O3 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g 

int32_t main(){
  DESYNC;
  int t; cin>>t;
  while(t--){
    int n, a; cin>>n;
    vector<vector<int>> graph(n+1, vector<int> ());

    for(int i=1; i<=n; i++){
      cin>>a;
      graph[a].pb(i);
    }

    int ans=n;
    for(int i=1; i<=n; i++){
      if((int)graph[i].size() > 0){
        graph[i].insert(graph[i].begin(), 0);
        graph[i].pb(n+1);
        
        int tmp = 0;
        for(int j=1; j<(int)graph[i].size(); j++)
          tmp += (graph[i][j] - graph[i][j-1] > 1);
        
        ans = min(ans, tmp);
      }
    }
    cout<<ans<<endl;
  }
}