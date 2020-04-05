#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
int mat[4][4], t, count[150], ans[4][4];

int main(){
    cin>>t;
    while(t--){
        for(int i=0; i<110; i++)
            count[i] = 0;

        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++){
                cin>>mat[i][j];
                ans[i][j] = 0;
            }

        for(int i=0; i<3; i++){
            count[abs(mat[i][0] - mat[i][1])]+=2;
            count[abs(mat[i][2] - mat[i][1])]++;
        }

        int bigger=0, cc=0, flag=0;
        for(int i=0; i<110; i++)
            if(count[i] > cc)
               bigger = i, cc = count[i];
            
        for(int i=0; i<3; i++){
            if(abs(mat[i][0] - mat[i][1]) == bigger)
                ans[i][0] = 1, ans[i][1] = 1;

            if(abs(mat[i][0] - mat[i][2]) == bigger)
                ans[i][0] = 1, ans[i][2] = 1;

            if(abs(mat[i][1] - mat[i][2]) == bigger)
                ans[i][1] = 1, ans[i][2] = 1;
        }

        cout<<"Possiveis maletas: ";
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(!ans[i][j])
                    cout<< (!flag ? "":", ")<<mat[i][j], flag=1;
        cout<<";\n";
    }

}