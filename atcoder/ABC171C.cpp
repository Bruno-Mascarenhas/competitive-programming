#include <bits/stdc++.h>
#define ll long long
using namespace std;


signed main(){
    ll n;
    string ans = "";
    cin>>n;

    while(n>0){
        n-=1;
        ans += (n%26)+'a';
        n /= 26;
    }

    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}