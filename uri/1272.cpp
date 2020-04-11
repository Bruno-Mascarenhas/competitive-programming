#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string s, ans="";
        bool f=0;   
        getline(cin,s);
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z' && !f)
                ans+=s[i], f=1;
            if(s[i] == ' ')
                f=0;
        }
        cout<<ans<<endl;
    }

}