#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map<char,int> dict;
    int n,i;
    string aux;

    for(char x : {'G', 'Q', 'a', 'k', 'u'})
        dict[x] = 0;
    for(char x : {'I', 'S', 'b', 'l', 'v'})
        dict[x] = 1;
    for(char x : {'E', 'O', 'Y', 'c', 'm', 'w'})
        dict[x] = 2;
    for(char x : {'F', 'P', 'Z', 'd', 'n', 'x'})
        dict[x] = 3;
    for(char x : {'J', 'T', 'e', 'o', 'y'})
        dict[x] = 4;
    for(char x : {'D', 'N', 'X', 'f', 'p', 'z'})
        dict[x] = 5;
    for(char x : {'A', 'K', 'U', 'g', 'q'})
        dict[x] = 6;
    for(char x : {'C', 'M', 'W', 'h', 'r'})
        dict[x] = 7;
    for(char x : {'B', 'L', 'V', 'i', 's'})
        dict[x] = 8;
    for(char x : {'H', 'R', 'j', 't'})
        dict[x] = 9;

    cin>>n;
    cin.ignore();
    while(n--){
        i=0;
        getline(cin,aux);
        string ans="";
        for(char x: aux){
            if(dict.count(x)) ans+=(dict[x]+'0'),i++;
            if(i == 12) break;
        }
        cout<<ans<<endl;
    }
}