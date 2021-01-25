#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
#define pi 3.1415926535897932384626
#define pb push_back
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define EPS 1e-9
#define INF 1e9

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

inline int mod(int n){ return (n%1000000007); }
//Compilation flags // g++ -std=c++17 -O3 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g 

bool cmp(pii a, pii b){
  return a.ff + a.ss < b.ff + b.ss;
}

int n;
vector<pii> arr(1010);
vector<int> dp(1010, -1);

int f(int used, int pref){
  if(dp[used] != 1) return dp[used];

  if(used >= n || pref >= n) return INF;

  if(used == 0){
    dp[used] = min(0 + arr[pref].ff, f(used,pref+1));
  }

  dp[used] = min(dp[used-1] + arr[pref].ff, f(used, pref+1));
};

int32_t main(){
  DESYNC;
  cin>>n;

  for(int i=0; i<n; i++) cin>>arr[i].ff>>arr[i].ss;

  sort(arr.begin(), arr.end(), cmp);

  f(0, 0);

  for(int i=0; i<=n; i++) cout<<i<<"= "<<dp[i]<<endl;
}