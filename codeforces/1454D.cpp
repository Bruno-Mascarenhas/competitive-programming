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

vector<pair<ll, ll>> trial_division3(long long n) {
    vector<pair<ll ,ll>> factorization;
    int cnt;
    for (int d : {2, 3, 5}) {
      if(n%d ==0){
        cnt = 0;
        while (n % d == 0) {
          cnt++;
          n /= d;
        }
        factorization.push_back({d,cnt});
      }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        if(n%d == 0){
          cnt = 0;
          while (n % d == 0) {
              n /= d;
              cnt++;
          }
          factorization.push_back({d,cnt});
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back({n,1});
    return factorization;
}


int32_t main(){
  DESYNC;
  int t; cin>>t;
  while(t--){
    ll n; cin>>n;

    if(n <= 3){ cout<<1<<endl<<n<<endl; continue; }

    vector<pair<ll, ll>> ans = trial_division3(n);
    
    sort(ans.begin(), ans.end(), [&] (pair<ll,ll> a, pair<ll,ll> b) { return a.second == b.second ? a.first > b.first : a.second > b.second;});
    
    if(ans[0].second == 1){ cout<<1<<endl<<n<<endl; continue; }

    /*
    cout<<endl<<n<<endl;
    for(auto x: ans){
      cout<<x.first<<" "<<x.second<<endl;
    }
    */
    
    vector<ll> res; ll last = ans[0].first;
    for(int i=0; i<ans[0].second-1; i++)
      res.pb(ans[0].first);
    for(int i=1; i<(int)ans.size(); i++){
      last *= pow(ans[i].first, ans[i].second);
    }

    cout<<res.size()+1<<endl;
    for(ll x: res) cout<<x<<" ";
    cout<<last<<endl;

  }
}