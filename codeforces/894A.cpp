#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int n = s.size(), res = 0;

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            for(int k=j+1; k<n; k++)
                if(s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
                    res++;

    cout<<res<<endl;
}