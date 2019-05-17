#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int val,coins,x;
bitset<N> change;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>val>>coins;
    change[0] = 1;
    while(coins--){
        cin>>x;
        change |= change << x;
    }
    change[val]?cout<<"S\n":cout<<"N\n";
}