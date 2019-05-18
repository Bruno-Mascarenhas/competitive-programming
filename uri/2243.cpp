#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e5+10;
int arr[N],n,esq[N],dir[N],ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    esq[0] = dir[n-1] = ans = 1;
    for(int i=1; i<n; i++)
        esq[i] = min(arr[i],esq[i-1]+1);

    for(int i=n-2; i>=0; i--)
        dir[i] = min(arr[i],dir[i+1]+1);

    for(int i=0;i<n;i++) ans = max(ans,min(esq[i],dir[i]));

    cout<<ans<<endl;
}