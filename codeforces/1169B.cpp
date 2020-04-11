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

vii pairs; int n,m;
bool ok(int x, int y){
  for(auto pair: pairs)
    if(pair.ff!=x && pair.ff!=y && pair.ss!=x && pair.ss!=y){
      return false;
    }
  return true;
}

int32_t main(){
  DESYNC;
  cin>>n>>m;
  pairs.assign(m,pii());
  for(auto &it: pairs)cin>>it.ff>>it.ss;
  if(ok(pairs[0].ff,pairs[0].ss))
    return puts("YES"),0;
  for(int x: {pairs[0].ff,pairs[0].ss}){
    for(int i=1;i<m;i++){
      if(pairs[i].ff!=x && pairs[i].ss!=x){
        if(ok(x,pairs[i].ff) || ok(x,pairs[i].ss))
          return puts("YES"),0;
        else break;
      }
    }
  }
  puts("NO");
}



