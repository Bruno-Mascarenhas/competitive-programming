#include <bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;
ll ans,n,x,tmp;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  while(cin>>n && n){
    cin>>x; tmp=x;ans=abs(x);
    for(int i=1; i<n; i++){
      cin>>x;
      tmp = tmp+x;
      ans+=abs(tmp);
    }
    cout<<ans<<endl;
  }
}
