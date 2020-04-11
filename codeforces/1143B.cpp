#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxn = 1e5;
#define pb push_back
#define ll long long

ll calc(string s){
  ll tmp=1;int start=0;
  while(1){if(s[start]=='0')start++;else break;}
  for(int i=start; i<s.size();i++) tmp*=(s[i]-'0');
  return tmp;
}

string num; ll ans=1, sup;
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin>>num; int tam = num.size();
  for(int i=0; i<tam; i++) ans*=(num[i]-'0');
  for(int i=1; i<tam; i++){
    string s = num;
    s[i-1]-=1;
    for(int j=i; j<tam; j++) s[j] = '9';
    ans = max(ans,calc(s));
  }
  cout<<ans<<"\n";
  return 0;
}