#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t, n, c, m, x, ans, tmp;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ans = 0; tmp = 0;
        cin>>n>>c>>m;
        vector<int> arr(m);
        for(int &x: arr) cin>>x;
        sort(arr.rbegin(),arr.rend());
        if(c == 1){
            cout<<accumulate(arr.begin(),arr.end(),0)*2<<endl;
            continue;
        }
        for(int i=0; i<m; i+=c)
            ans+=arr[i]*2;
        cout<<ans<<endl;
    }
}