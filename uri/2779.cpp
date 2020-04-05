#include <bits/stdc++.h>
using namespace std;

bitset<101> arr;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,x;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>x;
        arr[x] = 1;
    }
    cout<<n-arr.count()<<endl;
}