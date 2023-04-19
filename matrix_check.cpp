#include <iostream>
using namespace std;

bool matrix_check_identity(double a[50][50], int m){
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<m ; j++){
            if ((i!=j && a[i][j]!=0) || (i==j && a[i][j]!=1)){
                return false;
                break;
            }
        }
    }
    return true;
}