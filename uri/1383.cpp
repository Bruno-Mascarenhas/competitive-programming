#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
int n, mat[11][11], t=0;

bool validRow(int row){
    int arr[11] = {};
    for(int i=0; i<9; i++)
        arr[mat[row][i]]++;
    for(int i=1; i<=9; i++)
        if(arr[i]!=1)
            return false;

    return true;
}

bool validCol(int col){
    int arr[11] = {};
    for(int i=0; i<9; i++)
        arr[mat[i][col]]++;
    for(int i=1; i<=9; i++)
        if(arr[i]!=1)
            return false;
    
    return true;
}

bool validBox(int box){
    int arr[11] = {}, ibox, jbox;
    if(box<3) 
        ibox = 0, jbox = 0;
    else if(box < 6)
        ibox = 3, jbox = 3;
    else 
        ibox = 6, jbox = 6;

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            arr[mat[i+ibox][j+jbox]]++;
    for(int i=1; i<=9; i++)
        if(arr[i]!=1)
            return false;

    return true;
}

bool valid(){
    for(int i=0; i<9; i++)
        if(!(validRow(i) && validCol(i) && validBox(i)))
            return false;
    return true;
}

int main(){
    cin>>n;
    while(n--){
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                cin>>mat[i][j];

        cout<<"Instancia "<<++t<<endl;
        cout<<(valid() ? "SIM\n" : "NAO\n")<<endl;
    }
}