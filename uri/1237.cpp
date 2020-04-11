#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string a,b;
int m,n,ans,tmp;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(getline(cin,a)){
        getline(cin,b);
        m = a.size(); n = b.size(); ans=0;
        if(n > m){ swap(a,b); swap(m,n); }

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(a[i] == b[j]){
                    tmp = 0;
                    for(int id = 0; id+j<n; id++)
                        if(a[id+i] == b[id+j]) tmp++;
                        else break;
                    ans = max(tmp,ans);
                }
            }

        cout<<ans<<endl;
    }
}