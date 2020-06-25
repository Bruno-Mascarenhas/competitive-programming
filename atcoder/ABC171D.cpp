#include <bits/stdc++.h>
#define ll long long
#define ss second
#define ff first
using namespace std;

int n, q, bi, ci;
ll tot;
vector<int> arr;
multiset<int> segments;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;

    arr.resize(n);

    for(int &x: arr){ 
        cin>>x;
        segments.insert(x);
        tot+=(ll)x;
    }

    cin>>q;
    while(q--){
        cin>>bi>>ci;
        int qtd = segments.count(bi);

        if(qtd){    
            tot -= (ll)qtd * (ll)bi;
            tot += (ll)qtd * (ll)ci;

            segments.erase(bi);

            auto it = segments.insert(ci);

            for(int i=1; i<qtd; i++)
                segments.insert(it,ci);
        }

        cout<<tot<<endl;
    }
}