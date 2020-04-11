#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double mat[13][13];

int main(){
    int n=12, m=12, l;
    char op;

    cin>>l>>op;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    double ans = 0;

    for(int j=0; j<m; j++)
        ans+=mat[l][j];

    cout<<fixed<<setprecision(1)<<(op == 'S' ? ans : ans/12)<<endl;
    
}