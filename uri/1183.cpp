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

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if( j > i)
                ans+=mat[i][j];

    cout<<fixed<<setprecision(1)<<(op == 'S' ? ans : ans/66.0)<<endl;
    
}