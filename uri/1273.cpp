#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, best, f=1;
int main (){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n && n>0){
        best = 0;
        if(!f) cout<<endl;
        else f = 0;
        vector<string> arr(n);
        for(auto &x:arr){ cin>>x; best = max(best,(int)x.size()); }
        for(int i=0; i<n; i++){
            for(int j=0; j<best-arr[i].size();j++) cout<<" ";
        cout<<arr[i]<<endl;
        }
    }
}