#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    getline(cin, s);
    bool f=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' ')
            cout<<s[i];
        else if(s[i] == 'p' && f==0)
            f=1;
        else 
            cout<<s[i],f=0;
    }
    cout<<endl;
}