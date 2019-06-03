#include <bits/stdc++.h>
using namespace std;
#define pc __builtin_popcount


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,b, f, ans;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        if(pc(a+1)!=1){
            ans=1;
            while(ans<=a)
                ans*=2;
            cout<<ans-1<<endl;
        }
        else{
            f  = 0;
            for(int i=2; i*i<=a; ++i)
                if(a%i==0){
                    cout<<a/i<<endl; f =1; break;
                }
            if(!f)cout<<1<<endl;
        }
    }
}