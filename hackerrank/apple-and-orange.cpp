#include <bits/stdc++.h>
using namespace std;

int s, t, a, b, m, n;

bool intersect(int x){
    if(x >= s && x <= t)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>s>>t>>a>>b>>m>>n;
    int ans = 0, ans2 = 0;

    //m = apple, n = orange
    vector<int> apples(m), oranges(n);

    for(int &x: apples){ 
        cin>>x;
        x += a;
        if(intersect(x)) ans++;
    }

    for(int &x: oranges){
        cin>>x;
        x += b;
        if(intersect(x)) ans2++;
    }

    cout<<ans<<endl<<ans2<<endl;
}