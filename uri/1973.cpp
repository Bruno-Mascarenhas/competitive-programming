#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e6+10;
int arr[maxn], n, nx;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    unordered_set<int> nums;
    long long ans=0, tot=0;
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i], ans+=arr[i];
    int i=0;
    while(arr[i]){
        nums.insert(i);
        arr[i]%2 == 0 ? nx=-1 : nx=1;
        tot++, arr[i]--;
        i+=nx;
        if(i<0 || i==n) break;
    }

    cout<<nums.size()<<" "<<ans-tot<<endl;
}