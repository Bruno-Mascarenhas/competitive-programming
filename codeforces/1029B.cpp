#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;

int arr[N],n, curr=1, ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n; i++) cin>>arr[i];
    for(int i=0; i<n-1; i++)
        if(arr[i+1]<=arr[i]*2)
            curr++;
        else{
            ans = max(curr,ans);
            curr = 1;
        }
    cout<<max(ans,curr)<<endl;
}