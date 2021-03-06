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
#define ALL(x) for(int i=0; i<x; i++)
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

inline int mod(int n, int m){ auto x = n%m; if(x<0)x+=m; return x;}

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}

int fpow(int x, unsigned int y, int p){ 
    int res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
} 

int n, m, x, y; set<pii> seg; vi k;
int32_t main(){
  DESYNC;
  cin>>n>>m;
  fori(i,0,m){
    cin>>x>>y;
    x--;y--;
    if(x>y) swap(x,y);
    seg.insert({x,y});
  }

  int aux = n, cont = 0;
  
  k.pb(1);
  for(int i=2; i*i<=n; i++){
    if(aux%i==0){
      //cont=0;
      //while(aux%i==0){cont++; aux/=i;}
      k.pb(i);
      if(i!=aux/i) k.pb(aux/i);
    }
  }
  //if(aux>1) k.pb(aux);
  
  bool flag = 0;

  for(int d :k){
    flag = 1;
    for(auto it: seg){
      x = mod(it.ff+d,n);
      y = mod(it.ss+d,n);
      if(x>y) swap(x,y);  
      //cout<<x<<" "<<y<<"====="<<it.ff<<" "<<it.ss<<" "<<d<<endl;
      if(seg.count({x,y})==0){ flag = 0; break;}
    }
    if(flag) break;
  }
  flag ? cout<<"yes\n" : cout<<"no\n";
}