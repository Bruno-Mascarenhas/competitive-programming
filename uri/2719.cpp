#include <bits/stdc++.h>
using namespace std;


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,n,m, x;
    cin>>t;
    while(t--){
        int tmp=0, ans=1;
        cin>>n>>m;

        for(int i=0 ; i<n; i++){
            cin>>x;
            if(tmp+x>m) ans++,tmp=x;
            else tmp+=x;
        }

        cout<<ans<<endl;
    }

}