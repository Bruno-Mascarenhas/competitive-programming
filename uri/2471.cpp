#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
int mat[55][55], n;


int main(){
    cin>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>mat[i][j];

    int soma[3], somaReal=0, xerr=0, yerr=0;

    for(int i=0; i<3; i++){
        int tmp = 0;
        for(int j=0; j<n; j++)
            tmp+=mat[i][j];
        soma[i] = tmp;
    }

    for(int i=0; i<3; i++){
        if(soma[i] == soma[(i+1)%3 && soma[i] == soma[(i+2)%3]]){
            somaReal = soma[i];
            break;
        }
        if(i){
            if(soma[i] == soma[(i+1)%3] && soma[i] == soma[i-1]){
                somaReal = soma[i];
                break;
            }
        }
    }

    //row
    for(int i=0; i<n; i++){
        int tmp = 0;
        for(int j=0; j<n; j++)
            tmp+= mat[i][j];
        if(tmp != somaReal){
            xerr = i;
            break;
        }
    }

    //collumn
    int tmp;
    for(int i=0; i<n; i++){
        tmp = 0;
        for(int j=0; j<n; j++)
            tmp+= mat[j][i];
        if(tmp != somaReal){
            yerr = i;
            break;
        }
    }

    cout<<somaReal-(tmp-mat[xerr][yerr])<<" "<<mat[xerr][yerr]<<endl;
}