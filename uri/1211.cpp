#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

string s, tmp; int n, ans, tam;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n){
        ans = 0;
        vector<string> arr(n);
        for(string &x: arr) cin>>x;
        sort(arr.begin(),arr.end());
        tmp = arr[0]; tam = tmp.size();
        for(int i=1; i<n; i++)
            for(int j=0; j<tam; j++){
                if(arr[i][j] == tmp[j]) ans++;
                else{ tmp = arr[i]; break; }
            }
        cout<<ans<<endl;
    }
}