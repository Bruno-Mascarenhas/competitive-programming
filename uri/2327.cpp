#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int mat[110][110], n, m, soma=0, flag=0;

int main(){
    cin>>n;
    m = n;

    for(int i=0; i<n; i++)  
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    for(int i=0; i<n; i++) soma+=mat[0][i];

    //row
    for(int i=0; i<n; i++){
        int tmp=0;
        for(int j=0; j<m; j++)
            tmp+=mat[i][j];
        if(tmp != soma) flag = 1;
    }
    
    //column
    for(int i=0; i<m; i++){
        int tmp=0;
        for(int j=0; j<n; j++)
            tmp+=mat[j][i];
        if(tmp != soma) flag = 1;
    }
    
    //diagon
    int tmp=0;
    for(int i=0; i<n; i++) tmp+= mat[i][i];
    if(tmp!=soma) flag = 1;
    //diagon
    tmp = 0;
    for(int i=n-1, j=0; j<n; i--, j++) tmp+=mat[i][j];
    if(tmp!=soma) flag = 1;

    
    cout<<(flag ? -1 : soma)<<endl;
}