#include <bits/stdc++.h>
using namespace std;
#define pc __builtin_popcount

int n;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    vector<int> a(n), b(n), diff1, diff2;
    for(int &x :a) cin>>x; for(int &x :b) cin>>x;
    if(a[0] != b[0]) return puts("No"), 0;
    for(int i=1; i<n; i++){
        diff1.push_back(a[i]-a[i-1]);
        diff2.push_back(b[i]-b[i-1]);
    }
    sort(diff1.begin(),diff1.end()); sort(diff2.begin(),diff2.end());
    diff1 == diff2 ? puts("Yes") : puts("No");
}