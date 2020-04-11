#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

const int N = 3e5+10;
int n,x[N],y[N],resp1[N],resp2[N],l=0,r=0,ans[N];
int32_t main(){
  DESYNC;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>x[i]>>y[i];
    if(y[i]<x[i])resp1[l++]=i;
    else resp2[r++]=i;
  }
  if(l > r){
    sort(resp1,resp1+l,[](int a, int b){return y[a] < y[b];});
    cout<<l<<endl;
    for(int i=0; i<l; i++) cout<<resp1[i]+1<<" ";
    cout<<endl;
  }
  else{
    sort(resp2,resp2+r,[](int a, int b){return x[a] > x[b];});
    cout<<r<<endl; 
    for(int i=0; i<r; i++) cout<<resp2[i]+1<<" ";
      cout<<endl;
  }
}