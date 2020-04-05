#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<unsigned long long> calc(int n){
    if(n ==1 || n == 2){
        vector<unsigned long long> ans(n,1);
        return ans;
    }
    else{
    vector<unsigned long long> ans(n,1);
    for(int i=2; i<n; i++)
        ans[i] = ans[i-1] + ans[i-2];
    return ans;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;    
    vector<unsigned long long> fib = calc(40);

    set<unsigned long long> nums(fib.begin(),fib.end());

    vector<int> arr;

    for(int i=1; i<(int)1e6+10;i++){
        if(nums.count(i)==0)
            arr.push_back(i);
    }
    cout<<arr[n-1]<<endl;
}