#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        vector<int> arr(n), w(n);
        for(int &x: arr)cin>>x;
        for(int &x: w)cin>>x;
        int ans=0, ordenado=0;
        while(!ordenado){
            ordenado = 1;
            for(int i=0; i<n-1; i++)
                if(arr[i]>arr[i+1]){
                    swap(arr[i],arr[i+1]);
                    swap(w[i],w[i+1]);
                    ans+=w[i] + w[i+1];
                    ordenado = 0;
                }
        }
        cout<<ans<<endl;
    }
}