#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool can(int pref, int n, int c){
    return (pref <= c && c <= pref*(2*n-pref+1)/2);
}

void testcase(){
    int n, c;
    cin>>n>>c;
    if(!(n-1 <= c && c <= n*(n+1)/2 - 1)) return void(cout<<"IMPOSSIBLE"<<endl);
    
    vector<int> ans(n);
    for(int i=0; i<n; i++) ans[i] = i+1;

    for(int i=n-2; i>= 0; i--){
        for(int j=1; j<=n-i; j++){
            if(can(i,n,c-j)){
                reverse(ans.begin()+i, ans.begin()+i+j);
                c -= j;
                break;
            }
        }
    }

    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int main(){
    int t; cin>>t;
    for(int cx=1; cx<=t; cx++){
        cout<<"Case #"<<cx<<": ";
        testcase();
    }
}