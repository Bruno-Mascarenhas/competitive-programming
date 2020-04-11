#include <bits/stdc++.h>
using namespace std;
#define pc __builtin_popcount

int n,h,milks;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>h;
    vector<int> arr(n);
    for(int &x: arr)cin>>x;
    for(int i=0; i<n; i++){
        milks = 0;
        sort(arr.begin(),arr.begin()+i+1,greater<int>());
        for(int j=0; j<=i; j+=2)
            milks+=arr[j];
        if(milks>h)
            return cout<<i<<endl,0;
    }
    cout<<n<<endl;
}