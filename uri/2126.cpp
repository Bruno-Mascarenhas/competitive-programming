#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string patt; int t =0;
    while(cin>>patt){
        string s;
        int ans = 0;
        vector<int> loc;
        cin>>s;
        int pos=s.find(patt);
        while(pos!=string::npos){
            ans++;
            pos = s.find(patt,pos+1);
            loc.push_back(pos);
        }
        cout<<"Caso #"<<++t<<":\n";
        if(ans){
            loc.pop_back();
            cout<<"Qtd.Subsequencias: "<<ans<<endl<<"Pos: "<<loc.back()+1<<endl<<endl;
        }
        else 
            cout<<"Nao existe subsequencia"<<endl<<endl;
    }
}