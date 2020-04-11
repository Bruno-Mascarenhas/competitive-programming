#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        set<pair<int,string>> seq;
        int x,i=0; string s;
        while(n--){
            cin>>s>>x;
            seq.insert({x,s});
        }    
        for(auto it:seq) cout<<it.second<<(i+1 == seq.size()?"" : " "),i++;
        cout<<endl;
    }
}