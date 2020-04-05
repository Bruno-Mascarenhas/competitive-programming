#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        string s1, s2, ans="";
        cin>>s1>>s2;
        int i, j;
        for(i=0, j=0;i<s1.size() && j<s2.size(); i++,j++)
            ans+=s1[i], ans+=s2[j];
        
        if(i<s1.size()) ans+= s1.substr(i,s1.size());
        else if(j<s2.size()) ans+= s2.substr(j,s2.size());

        cout<<ans<<endl;
    }

}