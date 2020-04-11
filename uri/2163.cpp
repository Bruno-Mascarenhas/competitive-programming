#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
    
int n,m, mat[1010][1010];

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    for(int i=1; i<n-1; i++)
        for(int j=1; j<m-1; j++)
            if(mat[i][j] == 42 && mat[i-1][j] == 7 && mat[i+1][j] == 7
                                && mat[i-1][j-1] == 7 && mat[i-1][j+1] == 7
                                && mat[i][j-1] == 7 && mat[i][j+1] == 7
                                && mat[i+1][j-1] == 7 && mat[i+1][j+1] == 7)
                return cout<<i+1<<" "<<j+1<<endl, 0;

    cout<<0<<" "<<0<<endl;
}