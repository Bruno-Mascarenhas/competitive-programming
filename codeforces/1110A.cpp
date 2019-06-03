#include <bits/stdc++.h>
using namespace std;

int n, k, f, arr[(int)1e5+10], odd, even;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    if(n%2 == 0)
        f = 1;    
    for(int i=0; i<k; i++){
        cin>>arr[i];
        (arr[i]%2==0) ? even++ : odd++;
    }
    if(f)
        return cout<<(arr[k-1]%2==0?"even\n":"odd\n"),0;
    else
        return cout<<(odd%2==0?"even\n":"odd\n"),0;
}