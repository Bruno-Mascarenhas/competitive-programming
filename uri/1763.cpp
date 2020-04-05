#include <bits/stdc++.h>
using namespace std;
#define int long long

map<string,string> dict = {{
"brasil",              "Feliz Natal!"},
{"alemanha"        ,    "Frohliche Weihnachten!"},
{"austria"     ,        "Frohe Weihnacht!"},
{"coreia"     ,         "Chuk Sung Tan!"},
{"espanha"   ,          "Feliz Navidad!"},
{"grecia"    ,          "Kala Christougena!"},
{"estados-unidos"  ,    "Merry Christmas!"},
{"inglaterra"    ,      "Merry Christmas!"},
{"australia"   ,        "Merry Christmas!"},
{"portugal"   ,         "Feliz Natal!"},
{"suecia"  ,            "God Jul!"},
{"turquia"   ,          "Mutlu Noeller"},
{"argentina"  ,         "Feliz Navidad!"},
{"chile"   ,            "Feliz Navidad!"},
{"mexico"    ,          "Feliz Navidad!"},
{"antardida"   ,        "Merry Christmas!"},
{"canada"      ,        "Merry Christmas!"},
{"irlanda"     ,        "Nollaig Shona Dhuit!"},
{"belgica"    ,         "Zalig Kerstfeest!"},
{"italia"   ,           "Buon Natale!"},
{"libia"     ,          "Buon Natale!"},
{"siria"     ,          "Milad Mubarak!"},
{"marrocos"  ,          "Milad Mubarak!"},
{"japao"     ,          "Merii Kurisumasu!"}
};

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    while(cin>>s){
        if(dict.count(s)) cout<<dict[s]<<endl;
        else cout<<"--- NOT FOUND ---"<<endl;
    }
}