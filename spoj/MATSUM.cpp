#include <bits/stdc++.h>
#define m0(x) memset(x,0, sizeof x)
#define endl '\n'
using namespace std;
 
int bit[1050][1050], mat[1050][1050],n,t,x11,y11,x2,y2,val; string op;
 
void update(int x, int y, int val){
    for(;x<=1050;x+=x&-x)
        for(int j = y;j<=1050;j+=j&-j)
            bit[x][j]+=val;
}
 
int sum(int x, int y){
    int ans = 0;
    for(;x>0;x-=x&-x)
        for(int j=y; j>0; j-=j&-j)
            ans+=bit[x][j];
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        m0(bit); m0(mat);
        while(cin>>op && op!="END"){
            if(op == "SET"){
                cin>>x11>>y11>>val;x11++;y11++;
                int diff = val-mat[x11][y11];
                mat[x11][y11] = val;
                update(x11,y11,diff);
            }
            else if(op == "SUM"){
                cin>>x11>>y11>>x2>>y2;  x2++;y2++;
                cout<<sum(x11,y11)+sum(x2,y2)-sum(x11,y2)-sum(x2,y11)<<endl;
            }
        }
    }
} 
