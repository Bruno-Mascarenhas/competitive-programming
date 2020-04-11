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
    
    vector<unsigned long long> fib = calc(n);
    
    for(auto i=fib.rbegin(); i!=fib.rend();i++)
        cout<<(i!=fib.rbegin()?" ":"")<<*i;
    cout<<endl;

}