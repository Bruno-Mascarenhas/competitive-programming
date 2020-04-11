#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int l,c,r1,r2;
    while(cin>>l>>c>>r1>>r2 && l+c){
        if(l<c) swap(l,c);
        if(r1<r2) swap(r1,r2);
        
        if(2*r1 > l || 2*r1 > c){
            puts("N");
            continue;
        }

        pair<int,int> pt1 = {r1,r1}, pt2 = {l-r2,c-r2};
        if(hypot(pt1.first - pt2.first,pt1.second - pt2.second) >= r1+r2)
            puts("S");
        else 
            puts("N");
    }
}