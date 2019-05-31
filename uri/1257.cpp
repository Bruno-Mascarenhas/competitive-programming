#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n, ans, t;
string s;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--){
        cin>>t; ans = 0;
        for(int i=0; i<t; i++){
            cin>>s;
            for(int j=0; j<s.size();j++)
                ans+=(s[j]-'A')+i+j;
        }
        cout<<ans<<endl;
    }
    return 0;
}