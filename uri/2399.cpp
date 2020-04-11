#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++){
        cin>>x;
        if(x){
            if(i) arr[i-1]++;
            arr[i]++;
            if(i+1<n)arr[i+1]++;
        }
    }   
    for(int el: arr) cout<<el<<endl;

}