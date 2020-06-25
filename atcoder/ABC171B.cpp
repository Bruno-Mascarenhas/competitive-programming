#include <bits/stdc++.h>
#define ll long long
using namespace std;


signed main(){
    int n,k, ans=0;
    cin>>n>>k;
    vector<int> arr(n);
    for(int &x: arr) cin>>x;
    sort(arr.begin(), arr.end());
    for(int i=0; i<k; i++) ans+= arr[i];
    cout<<ans<<endl;
}   