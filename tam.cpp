#include <iostream>
#include "matrix_calculating.cpp"
#include "input_output_matrix.cpp"

int main(){
    double mt[50][50];
    int dai, rong;
    matrix_1_input(mt, dai, rong);
    cout << matrix_det(mt, dai) << endl;    
    system("pause");
    return 0;
}