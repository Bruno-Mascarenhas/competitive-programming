#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int n,m,t,q;
char mat[1010][1010];
int dx[] = {1, 0, -1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

bool valid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m && mat[x][y] == 'T')
        return true;
    return false;
}

bool coloca(int x, int y){
    int cnt =0;
    for(int i=0; i<8; i++)
        if(valid(x+dx[i],y+dy[i]))
            cnt++;
    
    return cnt < 5;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>q;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];

        while(q--){
            int x, y;
            cin>>x>>y;
            x--,y--;
            cout<<(coloca(x,y) ? "GG IZI" : "GRRR")<<endl;
        }
    }   
}