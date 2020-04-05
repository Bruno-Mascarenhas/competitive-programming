#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    while(cin>>s){
        int i=1, sum1=0, sum2=0, d1, d2;
        for(char x:s){
            if(isdigit(x)){
                sum1 += (x-'0') * i;
                sum2 += (x-'0') * (10-i);
                i++;
            }
            if(i == 10) break;
        }
        (sum1%11 == 10) ? d1 = 0 : d1 = sum1%11;
        (sum2%11 == 10) ? d2 = 0 : d2 = sum2%11;
        cout<<"CPF "<<((d2 == s[s.size()-1]-'0' && d1 == s[s.size()-2]-'0')?"valido\n":"invalido\n");
    }

}