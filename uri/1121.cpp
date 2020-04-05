#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
char mat[101][101];
int dirx[] = {0,0,-1,1}; // esq, dir, cima, baixo
int diry[] = {-1,1,0,0};
int n, m, tam, init, nx, ny, x, y;
string op; 
char atual;

bool valid(int xx, int yy){
    if((xx<n && xx>=0 && yy<m && yy>=0) && mat[xx][yy]!='#')
        return true;
    else 
        return false;
}

int main(){

    while(cin>>n>>m>>tam, n && m && tam){

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
                if(mat[i][j] == 'O')
                    nx = dirx[0], ny = diry[0], x = i, y = j, atual = 'O';
                else if(mat[i][j] == 'L')
                    nx = dirx[1], ny = diry[1], x = i, y = j, atual = 'L';
                else if(mat[i][j] == 'N')
                    nx = dirx[2], ny = diry[2], x = i, y = j, atual = 'N';
                else if(mat[i][j] == 'S')
                    nx = dirx[3], ny = diry[3], x = i, y = j, atual = 'S';
            }
        
        cin>>op;
        int ans=0;

        for(int i=0; i<tam; i++){
            //cout<<x<<" "<<y<<endl;
            if(op[i] == 'F'){
                if(valid(x+nx,y+ny))
                    x+=nx, y+=ny;
                if(mat[x][y] == '*') 
                    ans++, mat[x][y] = 'X';

            }
            //  N S L O // dir = O L N S [0 1 2 3]
            else if(op[i] == 'D'){
                if(atual == 'N')
                    nx = dirx[1], ny = diry[1], atual = 'L';
                else if(atual == 'S')
                    nx = dirx[0], ny = diry[0], atual = 'O';
                else if(atual == 'L')
                    nx = dirx[3], ny = diry[3], atual = 'S';
                else
                    nx = dirx[2], ny = diry[2], atual = 'N';
            }
            else{
                if(atual == 'N')
                    nx = dirx[0], ny = diry[0], atual = 'O';
                else if(atual == 'S')
                    nx = dirx[1], ny = diry[1], atual = 'L';
                else if(atual == 'L')
                    nx = dirx[2], ny = diry[2], atual = 'N';
                else
                    nx = dirx[3], ny = diry[3], atual = 'S';
            }
        }

        cout<<ans<<endl;
    }
}