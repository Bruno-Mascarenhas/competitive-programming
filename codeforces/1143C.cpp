#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxn = 1e5;
#define pb push_back

int n,x,ans,w[maxn]; vi g[maxn];
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
  for(int i=0; i<n; i++){
    cin>>x>>w[i]; x--;
    if(x>=0)
      g[x].pb(i);
  }
  bool f;
  for(int i=0; i<n; i++){
    f = 1;
    if(w[i]==1){
      for(int children:g[i]){
        if(w[children] != 1)
          f = 0;
      }
      if(f){ cout<<i+1<<"\n";ans++;}
    }
  }
  if(!ans) cout<<"-1\n";
  return 0;
}