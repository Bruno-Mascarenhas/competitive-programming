#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    set<string> cnt;
    string s;
    while(cin>>s){
        cnt.insert(s);
    }
    cout<<cnt.size()<<endl;
}