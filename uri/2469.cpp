#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, x;
    pair<int,int> ans = {0,0};
    cin>>n;
    unordered_map<int,int> freq;
    for(int i=0; i<n; i++){
        cin>>x;
        freq[x]++;
    }

    for(auto it = freq.begin(); it!=freq.end(); it++){
        if(it->ss > ans.ss)
            ans.ff = it->ff, ans.ss = it->ss;
        else if(it->ss == ans.ss)
            ans.ff = max(ans.ff, it->ff);
    }

    cout<<ans.ff<<endl;

}