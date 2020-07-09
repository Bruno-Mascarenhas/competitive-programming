#include <bits/stdc++.h>
#define ll long long
using namespace std;


signed main(){
    int H, W, k, ans = 0, cnt;
    char mat[10][10];

    cin>>H>>W>>k;

    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            cin>>mat[i][j];

    for(int maskh=0; maskh < (1<<H); maskh++)
        for(int maskw=0; maskw < (1<<W); maskw++){
            cnt = 0;

            for(int i=0; i<H; i++)
                for(int j=0; j<W; j++)
                    if( ((maskh>>i)&1) == 0 && ((maskw>>j)&1) == 0 && mat[i][j] == '#')
                        cnt++;

            if(cnt == k) ans++;
        }

    cout<<ans<<endl;
}