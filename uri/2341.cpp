#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k, x;
    cin>>n>>k;
    vector<int> arr(k+1,0);

    for(int i=0; i<n; i++){
        cin>>x;
        arr[x]++;
    }
    cout<<*min_element(arr.begin()+1,arr.end())<<endl;
}