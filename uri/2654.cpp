#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, poder, matou, morreu; string nome;
    cin>>n;
    vector<tuple<int,int,int,string>> arr(n);
    for(auto &x: arr){
        cin>>nome>>poder>>matou>>morreu;
        x = make_tuple(-poder,-matou,morreu,nome);
    }
    sort(arr.begin(),arr.end());
    cout<<get<3>(arr[0])<<endl;
}