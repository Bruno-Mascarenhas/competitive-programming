#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
char mat[1010][1010];
int n, m, vis[1010][1010];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m && mat[x][y]!='@')
        return true;
    return false;
}

void go(int x, int y, int days, int dir){
    !vis[x][y] ? vis[x][y] = days : vis[x][y] = min(days,vis[x][y]);

    if(dir>3){
        for(int i=0; i<4; i++)
            if(valid(x+dx[i],y+dy[i]))
                go(x+dx[i],y+dy[i],days+1,i);
    }
    else{
        if(valid(x+dx[dir],y+dy[dir]))
            go(x+dx[dir],y+dy[dir],days+1,dir);
    }
}

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!vis[i][j] && mat[i][j] == '@')
                go(i,j,0,5);

    int ans = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(mat[i][j]!='@' && !vis[i][j])
                return cout<<-1<<endl, 0;
            else
                ans = max(ans,vis[i][j]);

    cout<<ans<<endl;
}