#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    string s;
    while(cin>>n){
        cin.ignore();
        while(n--){
            getline(cin,s);
            int spc=0, pt=0;
            for(char x: s){ if(x == ' ') spc++; if(x == '.') pt++;}
            if(spc+1 == pt) cout<<(char)('a'+3*spc)<<endl;
            else if(pt == 2*(spc+1)) cout<<(char)('a'+3*spc+1)<<endl;
            else cout<<(char)('a'+3*spc+2)<<endl;
        }
    }
}