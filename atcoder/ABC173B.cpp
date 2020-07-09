#include <bits/stdc++.h>
#define ll long long
using namespace std;


signed main(){
    unordered_map<string,int> cnt;
    cnt["RE"] = 0; cnt["TLE"] = 0;  cnt["WA"] = 0;cnt["AC"] = 0;   
    int n; cin>>n; string s;
    for(int i=0; i<n; i++){
        cin>>s;
        cnt[s]++;
    }

    for(auto x : {"AC", "WA", "TLE", "RE"})
    cout<<x<<" x "<<cnt[x]<<endl;
}