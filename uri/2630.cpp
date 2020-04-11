#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    vector<int> arr(3);
    cin>>n;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        for(int &x: arr) cin>>x;
        cout<<"Caso #"<<i<<": ";
        if(s == "min")
            cout<<*min_element(arr.begin(),arr.end())<<endl;
        else if(s == "max")
            cout<<*max_element(arr.begin(),arr.end())<<endl;
        else if(s == "mean")
            cout<<fixed<<setprecision(0)<<floor(accumulate(arr.begin(),arr.end(),0)/3.0)<<endl;
        else 
            cout<<fixed<<setprecision(0)<<floor(arr[0]*0.3 + arr[1]*0.59 + arr[2]*0.11)<<endl;
    }
}