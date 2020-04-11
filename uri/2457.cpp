#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    char c; string s;
    int ans=0, f=0, cnt=0, f1=0;
    scanf("%c",&c);
    getline(cin,s);
    for(char x: s){
        if(x == ' ') f=0,f1=0;
        if(x!=' ' && !f1) cnt++,f1=1;
        if(x == c && f==0) f=1,ans++;
    }
    (ans) ? cout<<fixed<<setprecision(1)<<ans/(double)cnt*100<<endl : cout<<"0.0\n";
    //cout<<ans<<" "<<cnt<<endl;
}