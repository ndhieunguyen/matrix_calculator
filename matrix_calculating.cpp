#include <iostream>
using namespace std;

void swap(double& a, double& b){
    double tam=a;
    a=b;
    b=tam;
}

double sum_of_mul(double a[50][50], double b[50][50], int dong1, int cot2, int n){
    	double kq=0;
	    for (int i=0 ; i<n ; i++){
		    kq+=a[dong1][i]*b[i][cot2];
	    }
	    return kq;
    }

void matrix_sum(double a[50][50], double b[50][50], int m, int n, double c[50][50]){
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrix_mul(double a[50][50], double b[50][50] , int m, int n, int k, double c[50][50]){
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<k ; j++){
            c[i][j] = sum_of_mul(a, b, i, j, n);
        }
    }
}

void matrix_echelon(double a[50][50], int m, int n){
    for (int i=0 ; i<m ; i++){								//Khu ma tran de tao ra cac leading ones
		double k1=a[i][i];
		for (int j=0 ; j<n ; j++){
			if (k1!=0) a[i][j]/=k1;
		}
		for (int j=i+1 ; j<m ; j++){
			double k2=a[j][i];
			for (int k=0 ; k<n ; k++){
				if (k2!=0) a[j][k]=k2*a[i][k]-a[j][k];
			}
		}
    }
}

void matrix_reduce_echelon(double a[50][50], int m, int n){
	for (int i=1 ; i<m ; i++){								//Khu nguoc de tao ra ma tran don vi
		for (int j=0 ; j<i ; j++){
			double x=a[j][i];
			for (int k=i ; k<n ; k++){
				a[j][k]=-x*a[i][k]+a[j][k];
			}
		}
	}	
}

void matrix_inverse(double a[50][50], int m){
    for (int i=0 ; i<m ; i++){								//Ghi ma tran don vi canh ma tran da cho
		for (int j=m ; j<2*m ; j++){
			if (i==j-m) a[i][j]=1;
			else a[i][j]=0;
		}
	}
    matrix_echelon(a, m, 2*m);
    matrix_reduce_echelon(a, m, 2*m);
}

void matrix_T(double a[50][50], int m, int n, double b[50][50]){
    for (int i=0 ; i<max(m,n); i++){
        for (int j=0 ; j<max(m,n) ; j++){
            b[i][j] = a[j][i];
        }
    }
}

void matrix_system_solving(double a[50][50], int rank){
	matrix_echelon(a, rank, rank+1);
	matrix_reduce_echelon(a, rank, rank+1);
}

int matrix_rank(double a[50][50], int m, int n){
	matrix_echelon(a, m, n);
	int count=0;
	for (int i=0 ; i<m ; i++){
		if (a[i][i]==1) count++;
	}
	return count;
}

void matrix_echelon_for_det(double a[50][50], int m){
	for (int i=0 ; i<m ; i++){
		for (int j=i+1 ; j<m ; j++){
			double tam=-1*(a[j][i]/a[i][i]);
			for (int k=0 ; k<m ; k++){
				if (tam!=0) a[j][k]=tam*a[i][k]+a[j][k];
			}
		}
	}
}

int matrix_det(double a[50][50], int m){
	matrix_echelon_for_det(a, m);
	int kq=1;
	for (int i=0 ; i<m ; i++) kq*=a[i][i];
	return kq;
}