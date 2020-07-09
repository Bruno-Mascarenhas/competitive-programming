#include <bits/stdc++.h>
#define ll long long
#define ss second
#define ff first
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x1, x2;
    cin>>n;
    vector<int> inf, sup;

    for(int i=0; i<n; i++){
        cin>>x1>>x2;
        inf.push_back(x1); sup.push_back(x2);
    }

    sort(inf.begin(), inf.end());
    sort(sup.begin(), sup.end());

    if(n%2 == 0){
        int m1 = inf[n/2-1] + inf[n/2], m2 = sup[n/2-1] + sup[n/2];
        cout<<m2 - m1 + 1<<endl;
    } else {
        cout<<sup[n/2] - inf[n/2] + 1<<endl;
    }

}