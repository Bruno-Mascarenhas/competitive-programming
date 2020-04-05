#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    char c; string s;

    while(cin>>c>>s && c!='0'){
        int zero=0; string ans="";
        for(char x: s){
            if(x != c)
                ans+=x;
            if(x == '0')
                zero++;
        }
        if(zero == ans.size() || ans == ""){ cout<<0<<endl; }
        else{
            bool f =0;
            for(char x: ans){
                if(x != '0') f=1;
                if(f) cout<<x;
            }
            cout<<endl;
        }
    }
}