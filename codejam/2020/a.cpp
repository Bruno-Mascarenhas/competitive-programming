#include <bits/stdc++.h>
using namespace std;

set<int> row[101], col[101];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T,n,x;
  cin>>T;
  for(int i=1; i<=T; i++){

    int rc=0, rr=0, trace=0;
    cin>>n;
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++){
        cin>>x;
        if(i == j) trace+=x;
        row[i].insert(x);
        col[j].insert(x);
      }

    for(int i=0; i<n; i++){
      if(col[i].size()<n) rc++;
      if(row[i].size()<n) rr++;
    }

    cout<<"Case #"<<i<<": "<<trace<<" "<<rr<<" "<<rc<<"\n";

    for(int i=0; i<n; i++){
      row[i].clear();
      col[i].clear();
    }
  }
}
