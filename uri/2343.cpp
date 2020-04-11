#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int n, mat[1010][1010], x, y;

int main(){
    cin>>n;
    while(n--){
        cin>>x>>y;
        mat[x][y]++;
        if(mat[x][y] > 1)
            return cout<<1<<endl,0;
    }
    cout<<0<<endl;
}