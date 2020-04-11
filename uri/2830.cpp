#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a, b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    a--,b--;
    int ini = 0, fim = 15, mid, pos=1;

    while(ini<fim){
        mid = (ini+fim)/2;
        if(a <= mid && b > mid)
            break;
        else{
            pos++;
            if(a>=mid) ini = mid;
            else fim = mid;
        }
    }

    if(pos==1) cout<<"final"<<endl;
    else if(pos==2) cout<<"semifinal"<<endl;
    else if(pos==3) cout<<"quartas"<<endl;
    else cout<<"oitavas"<<endl;
}