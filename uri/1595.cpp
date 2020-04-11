#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long double ld;
int t, s, c, r;
ld ans;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ans = 0;
        cin>>s>>c>>r;
        vector<int> arr(s);
        for(int &x: arr) cin>>x;
        sort(arr.begin(),arr.end());
        for(int i=0; i<s;i++)
            if(c)ans+=1/((ld)arr[i]+r),c--;
            else ans+=1/(ld)arr[i];
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
}