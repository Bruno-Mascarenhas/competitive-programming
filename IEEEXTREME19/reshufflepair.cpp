#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
 
int main(){
    DESYNC;
	int q;
	cin >> q;
    for(int tt=0; tt<q;tt++){
        string s;
        cin >> s;
        int n = s.size();
        int prm[4] = {0,1,2,3};
        int v[4] = {0,0,0,0};
        int pf[4][2*n+1];
        pf[0][0] = pf[1][0] = pf[2][0] = pf[3][0];
        for(int i=0;i<n;i++)
            v[(s[i]-'A')]++;
        int ans = 1e9;
        s+=s;
        for(int i=0;i<2*n;i++){
            pf[0][i+1] = pf[0][i];
            pf[1][i+1] = pf[1][i];
            pf[2][i+1] = pf[2][i];
            pf[3][i+1] = pf[3][i];
            if(s[i]=='A'){
                pf[1][i+1]++;
                pf[2][i+1]++;
                pf[3][i+1]++;
            }
            else if(s[i]=='B'){
                pf[0][i+1]++;
                pf[2][i+1]++;
                pf[3][i+1]++;
            }
            else if(s[i]=='C'){
                pf[0][i+1]++;
                pf[1][i+1]++;
                pf[3][i+1]++;
            }
            else{
                pf[0][i+1]++;
                pf[1][i+1]++;
                pf[2][i+1]++;
            }
        }
        do{
            int resp = 0;
            int st = 0;
            for(int k=0;k<n;k++){
                st = k;
                for(int i=0;i<4;i++){
                    resp += pf[prm[i]][st+v[prm[i]]] - pf[prm[i]][st];
                    st += v[prm[i]];
                    
                }
                ans = min(ans,resp);
                resp = 0;
            }
    
        } while(next_permutation(prm, prm + 4));
        cout << ans/2 << endl;
    }
}