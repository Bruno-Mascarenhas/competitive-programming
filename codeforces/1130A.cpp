#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n, x, pos=0, neg=0, len;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>x;
        if(!x) continue;
        x > 0 ? pos++ : neg++;
    }

    len = (n+1)/2;
    if(pos >= len)
        cout<<1<<endl;
    else if(neg >= len)
        cout<<-1<<endl;
    else
        cout<<0<<endl;
}