#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e4+10;
int arr[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, ans, x;
    while(cin>>n>>m && n+m){
        ans = 0;
        for(int i=0; i<m; i++){
            cin>>x;
            arr[x]++;
        }
        for(int i=0; i<=n; i++) if(arr[i]>1) ans++;
        memset(arr,0,sizeof arr);
        cout<<ans<<endl;
    }

}