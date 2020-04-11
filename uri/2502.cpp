#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m; string a, b, aux; char tmp;
unordered_map<char,char> mapa1,mapa2;
set<char> comps = {'.',',',';',':','(',')','!','?'};
bool f(char a){
    return a >= 'A' && a <= 'Z' ? true : false;
}
bool f2(char a){
    if(!f(a) && comps.find(a) == comps.end()) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m){
        mapa1.clear(); mapa2.clear();
        cin.ignore();
        getline(cin,a);getline(cin,b);

        for(int i=0; i<a.size(); i++){
            if(f2(b[i]) && !isdigit(a[i])){
                mapa1[b[i]] = tolower(a[i]);
                mapa2[a[i]] = tolower(b[i]);
            }else {
                mapa1[b[i]] = a[i];
                mapa2[a[i]] = b[i];
            }
        }

        for(int k=0; k<m; k++){
            getline(cin,aux);
            for(char c: aux){
                if(mapa1.count(c) || mapa1.count(toupper(c))){ 
                    if(mapa1.count(c))
                        cout<<(char)mapa1[c];
                    else {
                        cout<<(f(c) ? (char)mapa1[toupper(c)] : (char)tolower(mapa1[toupper(c)]));
                    }
                }
                else if(mapa2.count(c) || mapa2.count(toupper(c))){ 
                    if(mapa2.count(c))
                        cout<<(char)mapa2[c];
                    else {
                        cout<<(f(c) ? (char)mapa2[toupper(c)] : (char)tolower(mapa2[toupper(c)]));
                    }
                }
                else cout<<c;
            }
            cout<<endl;
        }
        cout<<endl;
    }
}