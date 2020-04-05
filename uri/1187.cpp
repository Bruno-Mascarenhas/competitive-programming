#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double mat[13][13];

int main(){
    int n=12, m=12;
    char op;

    cin>>op;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    double ans = 0;
    int ini = 1, fim = 10;
    for(int i=0; i<5; i++){
        for(int j=ini; j<=fim; j++)
            ans+=mat[i][j];
        ini++, fim--;
    }

    cout<<fixed<<setprecision(1)<<(op == 'S' ? ans : ans/30)<<endl;
    
}