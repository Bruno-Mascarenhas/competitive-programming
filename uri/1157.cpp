#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> divs(int n){
    vector<int> ans;
    for(int i=1; i<n; i++)
        if(n%i==0)
            ans.push_back(i);
    ans.push_back(n);
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;

    vector<int> nums = divs(n);

    for(int x: nums) cout<<x<<endl;
}