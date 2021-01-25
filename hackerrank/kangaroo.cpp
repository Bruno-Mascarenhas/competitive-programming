#include <bits/stdc++.h>
using namespace std;

int main(){
    pair<int,int> k1, k2;
    cin>>k1.first>>k1.second>>k2.first>>k2.second;

    if(k1.first == k2.first)
        return cout<<"YES\n", 0;

    if(k1 < k2) swap(k1,k2);

    int v = k2.second - k1.second;

    if(v <= 0)
        return cout<<"NO\n", 0;

    cout<<(((k2.first - k1.first)%v) == 0 ? "YES" : "NO")<<endl;
}