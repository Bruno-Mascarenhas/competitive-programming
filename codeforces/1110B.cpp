#include <bits/stdc++.h>
using namespace std;

int n, k, m, arr[(int)1e5+10], ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    vector<int> dist;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i)
            dist.push_back(arr[i]-arr[i-1]);
    }
    sort(dist.rbegin(),dist.rend());
    ans = arr[n-1] - arr[0];
    for(int i=0; i<min(k-1,(int)dist.size());i++){
        ans-=dist[i];
    }
    cout<<ans+k<<endl;
}