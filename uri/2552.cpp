#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int n,m, mat[110][110], ans[110][110];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

int main(){
    while(cin>>n>>m){

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                ans[i][j] = 0;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
                if(mat[i][j])
                    for(int k=0; k<4; k++)
                        if(valid(i+dx[k],j+dy[k]))
                            ans[i+dx[k]][j+dy[k]]+=1;
            }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                cout<< (mat[i][j] ? 9 : ans[i][j]);
            cout<<endl;
        }
    }   
}