#include <bits/stdc++.h>
using namespace std;
#define pc __builtin_popcount

int n, ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    vector<int> arr(n);
    vector<int> dist(n,0);
    for(int &x:arr) cin>>x;
    for(int i=1; i<n; i++)
        if(arr[i]!=arr[0]) ans = i;
    for(int i=n-2; i>=0; i--)
        if(arr[i]!=arr[n-1]) ans = max(ans,n-i-1);
    cout<<ans<<endl;
}