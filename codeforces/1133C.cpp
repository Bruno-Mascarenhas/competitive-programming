#include <bits/stdc++.h>
using namespace std;

int n,fix,tmp,ans,j;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    vector<int> arr(n);
    for(int &x:arr) cin>>x;
    sort(arr.begin(),arr.end());
    ans=0;
    for(int i=0; i<n;i++){
        while(j<n && arr[j]-arr[i] <= 5) j++;
        ans = max(ans,j-i);
    }
    cout<<ans<<endl;
}