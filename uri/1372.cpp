#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e5+10;
int arr[N],dpl[N],dpr[N],n,m;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  while(cin>>m>>n && n+m>0){
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        cin>>arr[j];
        if(j>1)
          dpl[j] = max(dpl[j-2]+arr[j],dpl[j-1]);
        else if(j==0)
          dpl[j] = arr[j];
        else 
          dpl[j] = max(dpl[j-1],arr[j]);
      }
      if(i>1)
        dpr[i] = max(dpr[i-2]+dpl[n-1],dpr[i-1]);
      else if(i==0)
        dpr[i] = dpl[n-1];
      else 
        dpr[i] = max(dpr[i-1],dpl[n-1]);
    }
    cout<<dpr[m-1]<<endl;
  }
}
