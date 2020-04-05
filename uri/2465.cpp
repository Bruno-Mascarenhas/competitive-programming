#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int n, x, y, mat[110][110], vis[110][110], cnt=0;
int dirx[] = {1,0,-1,0};
int diry[] = {0,1,0,-1};

bool valid(int xx, int yy, int cur){
    if((xx>=0 && xx<n && yy>=0 && yy<n) && !vis[xx][yy] && mat[xx][yy]>=cur)
        return true;
    return false;
}

void go(int xxx, int yyy){
    cnt++;
    vis[xxx][yyy] = 1;
    for(int i=0; i<4; i++)
        if(valid(xxx+dirx[i],yyy+diry[i],mat[xxx][yyy])){
            go(xxx+dirx[i],yyy+diry[i]);
        }
}

int main(){
    cin>>n>>x>>y;
    x--,y--;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>mat[i][j];

    go(x,y);
    cout<<cnt<<endl;

}