#include <bits/stdc++.h>
using namespace std;
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

int n,m,ans; string s,tmp;
int32_t main(){
  DESYNC;
  cin>>n>>s>>m;
  vector<vector<int> > arr;
  arr.assign(n,vector<int>(30,0));
  for(int i=0; i<m; i++){
    cin>>tmp;
    for(int j=0; j<n; j++)
      if(tmp[j]!=s[j]) arr[j][tmp[j]-'A']++;
  }
  for(int i=0; i<n; i++)
    ans+=*max_element(arr[i].begin(),arr[i].end());
  cout<<ans<<endl;
}