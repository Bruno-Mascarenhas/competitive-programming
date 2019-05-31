#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>s){
        int tam = s.size();
        for(int j=s.size(); j>0; j--){
            for(int i=0; i<tam-j; i++)cout<<" ";
            for(int i=0; i<j; i++)
                cout<<s[i]<<(i<j-1?" ":"");
            cout<<endl;
        }
        cout<<endl;
    }
}