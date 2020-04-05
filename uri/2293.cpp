#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int mat[110][110], n, m, ans=0;

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++)  
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    for(int i=0; i<n; i++){
        int tmp=0;
        for(int j=0; j<m; j++)
            tmp+=mat[i][j];
        ans = max(ans,tmp);
    }
    
    for(int i=0; i<m; i++){
        int tmp=0;
        for(int j=0; j<n; j++)
            tmp+=mat[j][i];
        ans = max(ans,tmp);
    }

    cout<<ans<<endl;

}