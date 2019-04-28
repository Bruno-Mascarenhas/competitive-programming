#include <bits/stdc++.h>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
using namespace std;
const int maxn = 1e5+10;
int arr[maxn],n,inc[maxn],decr[maxn],q;

int32_t main(){
    DESYNC;
    cin>>n;

    inc[0] = decr[0] = 1;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i){
            if(arr[i] > arr[i-1]) inc[i] = inc[i-1]+1;
            else inc[i] = 1;

            if(arr[i] < arr[i-1]) decr[i] = decr[i-1]+1;
            else decr[i] = 1;
        }
    }

    cin>>q;
    int l,r;
    while(q--){ 
        cin>>l>>r;
        if(inc[r]>=r-l+1) cout<<"crescente\n";
        else if(decr[r]>=r-l+1) cout<<"decrescente\n";
        else cout<<"nenhum\n";
    }
}