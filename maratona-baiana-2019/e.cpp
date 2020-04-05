#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
using namespace std;
int n,k,x,y;
bool op;
typedef pair<int,int> pii;
bool valid(pii a, pii b){
    if(b.ff<a.ff+k && b.ss<a.ss+k && b.ff>a.ff-k && b.ss>a.ss-k)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    vector<pii> pts;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        pts.pb({x,y});
    }
    for(int i=0; i<n; i++){
        op = 1;
        for(int j=0; j<n; j++)
            if(j!=i)
                if(valid(pts[i],pts[j])){
                    puts("YES"),op^=op;break;}
        if(op)puts("NO");
    }
}