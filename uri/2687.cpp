#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
int mat[30][30], t, n, vis[30][30], cnt;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<n && !mat[x][y] && !vis[x][y])
        return true;
    return false;
}


void go(int x, int y){
    vis[x][y] = 1;
    cnt++;
    for(int i=0; i<4; i++)
        if(valid(x+dx[i],y+dy[i]))
            go(x+dx[i],y+dy[i]);
}

int main(){
    cin>>t;
    while(t--){
        cnt=0;
        for(int i=0; i<16; i++)
            for(int j=0; j<16; j++)
                vis[i][j]=0;        

        cin>>n;
        int total = n*n;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];

        for(int i=0; i<n; i++){
            if(!vis[0][i] && !mat[0][i])
                go(0,i);

            if(!vis[i][0] && !mat[i][0])
                go(i,0);
            
            if(!vis[i][n-1] && !mat[i][n-1])
                go(i,n-1);

            if(!vis[n-1][i] && !mat[n-1][i])
                go(n-1,i);
        }

        cout<<fixed<<setprecision(2)<<(total-cnt)/2.0<<endl;

    }
}