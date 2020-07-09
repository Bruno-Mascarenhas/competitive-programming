#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    int n;
    cin>>n;
    vector<int> arr(n), circle;

    for(int &x: arr) cin>>x;

    sort(arr.rbegin(), arr.rend());

    int ans = 0;
    for(int i=0; i<n ;i++){
        circle.push_back(arr[i]);
        if(i) circle.push_back(arr[i]);
    }

    for(int i=0; i<n-1; i++) ans += circle[i];
    
    cout<<ans<<endl;
}