#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        vector<int> arr(n);
        for(int &x: arr)cin>>x;
        sort(arr.begin(),arr.end());
        int qtd=0, minu = (int)1e6;
        for(int i=0; i<n/2; i++)
            if(arr[i] < arr[n-i-1]) qtd++, minu = min(arr[n-i-1] - arr[i],minu);
        cout<<qtd<<" "<<minu<<endl;
    }
}