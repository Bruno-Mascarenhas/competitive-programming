#include <bits/stdc++.h>
using namespace std;
int T, l, r, prv, cur;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  string str;
  cin>>T;

  for(int t=1; t<=T; t++){
    l=0, r=0;
    string ans = "";
    cin>>str;

    for(int i=0; i<str.size(); i++){
      cur = str[i]-'0';
      if(!i){
        ans += string(cur,'(');
        ans += str[i];
        r += cur;
      }
      else if(prv == cur)
        ans+= str[i];
      else if(prv < cur){
        ans += string(cur-prv,'(');
        ans += str[i];
        r += cur-prv;
      }
      else if(prv > cur){
        ans += string(prv-cur,')');
        ans += str[i];
        r -= prv-cur;
      }
      prv = cur;
      if(i == str.size()-1)
        ans += string(r,')');
    }
    cout<<"Case #"<<t<<": "<<ans<<"\n";
  }
}
