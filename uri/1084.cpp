#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+10;
int x[N], y[N], n;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    multiset<int> l, r;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
        l.insert(x), r.insert(y[i]);
    }
    int best = 0;
    for(int i=0; i<n; i++){
        l.erase(l.find(x[i])), r.erase(r.find(y[i]));
        best = max(best, *(r.begin()) - *(--l.begin()));
        l.insert(x[i]), r.insert(y[i]);
    }
    cout<<best<<endl;
}