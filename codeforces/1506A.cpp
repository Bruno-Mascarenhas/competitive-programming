#include <bits/stdc++.h>
#define int long long int
using namespace std;

void testcase(){
    int n, m, x;
    cin>>n>>m>>x;
    
    x--;

    int col = x/n, row = x%n; 

    cout<<row*m + col+1<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--)testcase();
}