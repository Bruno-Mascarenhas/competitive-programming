#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int k,n,m,aux; char vowel[] = {'a','e','i','o','u'};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>k;
    if(k < 5){ cout<<-1<<endl; return 0;}
    for(int n = 5; n*n<=k; n++){
        if(k%n == 0){
            m = k/n;
            if(m >= 5){
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++)
                        cout<<vowel[(j+aux)%5];
                    aux++;
                }
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}