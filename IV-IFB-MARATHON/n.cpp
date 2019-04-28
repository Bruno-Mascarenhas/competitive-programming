#include <bits/stdc++.h>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
const int maxn = 1e5+10;
typedef pair<int,int> pii;

bool comp(pii a, pii b){
    if(a.first > b.first)
        return true;
    if(a.first == b.first && a.second < b.second)
        return true;
    return false;

}
int32_t main(){
    int n,m,x,y;
    cin>>n>>m;

    pair<int,int> ans = {m,m*300};
    vector<pair<int,int> > arr;

    for(int i=0;i<n;i++){
        cin>>x>>y;
        arr.push_back({x,y});
    }
    arr.push_back(ans);

    sort(arr.begin(),arr.end(),comp);

    //cout<<ans.first<<" "<<ans.second<<endl;
    //cout<<arr[0].first<<" "<<arr[0].second<<endl;

    arr[0] == ans ? cout<<"S\n" : cout<<"N\n";
}