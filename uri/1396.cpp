#include <bits/stdc++.h>
using namespace std;

int n, k, t, bestpos, sorted, dist;
string best;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n>>k && n+k){
        vector<string> arr(n);
        for(auto &x: arr)cin>>x;
        sorted = 1;
        while(sorted){
            sorted = 0;
            for(int i=0; i<n-1;i++){
                dist = 0; best = arr[i]; bestpos = -1; sorted=0;
                for(int j=0; j<n-1; j++){
                    dist++;
                    if(arr[j]>arr[j+1] && dist <= k && arr[j+1] < best)
                        bestpos=j+1,best = arr[j+1];
                }
                if(bestpos!=-1){
                    sorted = 1;
                    for(int j=bestpos; j>i; j--) swap(arr[j],arr[j-1]);
                    k-=dist;
                }
            }
        }
        cout<<"Instancia "<<++t<<endl;
        for(auto x: arr)cout<<x<<" ";
        cout<<endl<<endl;
    }
}