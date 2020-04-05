#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define int long long
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

int32_t main(){
  DESYNC;
  int n;
  cin>>n;
  vector<int> arr(n),nxt(n),vis(n,0);
  for(int &x: arr)cin>>x;

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
      if(arr[i]%3 == 0 && arr[i]/3 == arr[j])
        nxt[i] = j, vis[j] = 1;
      else if(arr[i]*2 == arr[j])
        nxt[i] = j, vis[j] = 1;
    }

  int cur=0;
  for(int i=0; i<n; i++)
    if(!vis[i])
      cur = i;
  
  for(int i=0; i<n; i++){
    cout<<arr[cur]<<(i+1==n ?"\n":" ");
    cur = nxt[cur];
  }
}