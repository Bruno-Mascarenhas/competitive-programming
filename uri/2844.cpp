#include <bits/stdc++.h>
using namespace std;

int am, rm, em, av, rv, ev, tam;
string str;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  set<char> pont = {',','.','\\','/',';','[',']','-','=',' '};
  while(cin>>am>>rm>>em){
    cin>>av>>rv>>ev;
    cin.ignore();
    getline(cin,str);
    for(auto x: str){
        if(isalnum(x) || pont.count(x))
        tam++;
        else
        tam+=2;
    }
    double m = 2*am + rm + em * tam;
    double v = 2*av + rv + ev * tam;
    if(m == v) {cout<<"Empate\n"; return 0; }
    m < v ? cout<<"Matheus\n" : cout<<"Vinicius\n";
  }
}