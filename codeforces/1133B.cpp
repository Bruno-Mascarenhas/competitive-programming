#include <bits/stdc++.h>
using namespace std;

int n, k, freq[110],x, ans;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n; i++){
        cin>>x;
        freq[x%k]++;
    }
    ans += freq[0]/2;
    for(int i=1; i<(k+1)/2; i++)
        ans+=min(freq[i],freq[k-i]);
    if(k%2==0)
        ans+=freq[k/2]/2;

    cout<<ans*2<<endl;
}