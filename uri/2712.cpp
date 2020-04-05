#include <bits/stdc++.h>
using namespace std;
#define int long long

map<char,string> dict;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; string aux;
    dict['1'] = "MONDAY"; dict['2'] = "MONDAY";
    dict['3'] = "TUESDAY"; dict['4'] = "TUESDAY";
    dict['5'] = "WEDNESDAY"; dict['6'] = "WEDNESDAY";
    dict['7'] = "THURSDAY"; dict['8'] = "THURSDAY";
    dict['0'] = "FRIDAY"; dict['9'] = "FRIDAY";

    cin>>n;
    while(n--){
        cin>>aux;
        bool ok = 1;
        if(aux.size() != 8) ok = 0;
        else{
            for(int i=0; i<3; i++) if(aux[i]<'A' || aux[i]>'Z') ok = 0;
            for(int i=4; i<8; i++) if(aux[i]<'0' || aux[i]>'9') ok = 0;
            if(aux[3]!='-') ok = 0;
        }
        if(ok) cout<<dict[aux.back()]<<endl;
        else cout<<"FAILURE\n";
    }
}