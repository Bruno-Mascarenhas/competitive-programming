#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; int n, x;
    while(cin>>s){
        string ans="";
        cin>>n;
        for(int i=0; i<n; i++)  {
            cin>>x;
            ans+=s[--x];
        }
        cout<<ans<<endl;
    }
}