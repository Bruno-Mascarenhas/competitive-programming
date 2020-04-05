#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 65;
int arr[maxn][2];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, ans, x, j; char op;
    while(cin>>n){
        ans = 0;
        for(int i=0; i<n; i++){
            cin>>x>>op;
            op == 'E' ? j = 0 : j = 1;
            arr[x][j]++;
        }

        for(int i=0; i<maxn; i++)
            ans += min(arr[i][0],arr[i][1]);
        
        memset(arr,0,sizeof arr);

        cout<<ans<<endl;
    }

}