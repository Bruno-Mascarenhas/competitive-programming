#include<bits/stdc++.h>

using namespace std;

int n, t;
string s;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t; int f;
    while(t--){
        cin>>n>>s;
        reverse(s.begin(),s.end());
        f = 0;
        if(n < 11) { cout<<"NO\n"; continue;}
        for(int i=10; i<s.size(); i++)
            if(s[i]=='8') f = 1;
        f ? cout<<"YES\n":cout<<"NO\n";
    }
	return 0;
}