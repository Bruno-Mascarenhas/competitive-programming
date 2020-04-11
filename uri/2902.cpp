#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n && n){
        unordered_map<int,int> last;
        int ans=0,x;
        for(int i=0;i<n;i++){
            cin>>x;
            if(!last.count(x))
                ans+=x+i,last[x]=i;
            else
                ans+=i-last[x], last[x]=i;
        }
        cout<<ans<<endl;
    }    

}