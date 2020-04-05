#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,dist; string name; char dir;
    while(cin>>n){
        vector<tuple<int,char,string>> arr(n);
        for(auto &x: arr){
            cin>>name>>dir>>dist;
            x = make_tuple(dist,dir,name);
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++)
            cout<<get<2>(arr[i])<<endl;
    }
}