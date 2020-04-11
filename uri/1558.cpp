#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, i, j, f, tmp;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n){
        i = f = 0;
        j = sqrt(n);
        while(i<=j){
            tmp = i*i + j*j;
            if(tmp == n){ f=1; break;}
            if(tmp < n) i++;
            else j--;
        }
        cout<< (f? "YES\n":"NO\n");
    }
    return 0;
}