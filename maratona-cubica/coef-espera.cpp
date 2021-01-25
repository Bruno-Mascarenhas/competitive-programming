#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
#define int long long
#define pi 3.1415926535897932384626
#define pb push_back
#define ff first
#define ss second
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define EPS 1e-9
#define INF 1e18

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> indexed_set;

inline int mod(int n){ return (n%1000000007); }
//Compilation flags // g++ -std=c++17 -O3 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g 

int32_t main(){
  DESYNC;
  int t, k, n, x, y;
  cin>>t;
  while(t--){
      cin>>n>>k>>x>>y;
      vector<int> arr(n+1);
      int norm = 0, id = 1, ans = 0;

      for(int i=1; i<=n; i++){ cin>>arr[i]; ans+= max(0LL, arr[i]-x);}

      norm = ans;

      for(int i=1; i<k; i++) norm += max(0LL,arr[i]-y) - max(0LL, arr[i]-x);

      for(int i=k; i<=n; i++){
        norm += -max(0LL,arr[i-k]-y) + max(0LL,arr[i-k]-x);

        norm += max(0LL,arr[i]-y) - max(0LL, arr[i]-x);

        if(norm < ans){
          ans = norm;
          id = i-k+1;
        }
      }
      
      cout<<id<<" "<<ans<<endl;
  }
}