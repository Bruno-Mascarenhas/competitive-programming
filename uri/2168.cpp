#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int mat[110][110], n;

bool valid(int row, int col){
    int count = 0;
    for(int i=row; i<row+2; i++)
        for(int j=col; j<col+2; j++)
            if(mat[i][j]) 
                count++;
    return count > 1;
}

int main(){
    cin>>n;

    for(int i=0; i<n+1; i++)
        for(int j=0; j<n+1; j++)
            cin>>mat[i][j];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<(valid(i,j) ? "S" : "U");
        cout<<endl;
    }
}