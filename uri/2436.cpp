#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int n,m, mat[1010][1010], vis[1010][1010], x,y;
int dirx[] = {1,-1,0,0};
int diry[] = {0,0,1,-1};

bool valid(int xx, int yy){
    if((xx < n && xx >=0 && yy < m && yy>=0) && mat[xx][yy] == 1 && !vis[xx][yy])
        return true;
    return false;
}

int main(){

    cin>>n>>m>>x>>y;
    x--,y--;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    bool pass;

    for(int i=0; i<n*m; i++){
        pass=0;
        for(int j=0; j<4; j++)
            if(valid(x+dirx[j],y+diry[j])){
                pass=1,vis[x][y]=1,x+=dirx[j],y+=diry[j];
                break;
            }
        if(!pass)
            break;
    }

    cout<<x+1<<" "<<y+1<<endl;

}