#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
string s, aux;
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k>>s;
    int pos = 0;
    for(int i=1; i<n; i++)
        if(s.substr(0,i) == s.substr(n-i,n))
            pos = i;
    aux = s;
    for(int i=1; i<k; i++)
        s+=aux.substr(pos,n);
    cout<<s<<endl;
}