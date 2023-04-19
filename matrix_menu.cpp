#include <iostream>
#include "matrix_calculating.cpp"
#include "input_output_matrix.cpp"
#include "matrix_check.cpp"
using namespace std;

void menu(){
    int choice;
    system("cls");
    // SetColor(6);
    cout << "---------------Tinh toan ma tran----------------\n" << endl;
    // SetColor(7);
    cout << "0. Thoat" << endl;
    cout << "1. Tinh tong hai ma tran" << endl;
    cout << "2. Tinh tich hai ma tran" << endl;
    cout << "3. Tinh nghich dao cua ma tran" << endl;
    cout << "4. Tinh chuyen vi cua ma tran" << endl;
    cout << "5. Giai he phuong trinh bang ma tran" << endl;
    cout << "6. Tinh hang ma tran" << endl; 
    cout << "7. Tinh dinh thuc cua ma tran" << endl;
    cout << "Vui long lua chon: ";
    cin >> choice;
    switch (choice){
        case 1:{
            choice=1;
            while (choice){
                system("cls");
                // SetColor(6);
                cout << "----------Tinh tong hai ma tran----------\n\n";
                // SetColor(7);
                double mt1[50][50], mt2[50][50], mtkq[50][50];
                int sodong1, socot1, sodong2, socot2;
                matrix_2_input(mt1, mt2, sodong1, socot1, sodong2, socot2);
                if (sodong1==sodong2 && socot1==socot2){
                    matrix_sum(mt1, mt2, sodong1, socot1, mtkq);
                    matrix_1_output(mtkq, sodong1, socot1);
                }       
                else cout << "Hai ma tran phai co cung kich thuoc !!!\n\n";
                cout << "\n0. Tro ve\n1. Thu lai\nVui long lua chon: ";
                cin >> choice;
            }
            menu();
            break;     
        }
        case 2:{
            choice=1;
            while (choice){
                system("cls");
                // SetColor(6);
                cout << "----------Tinh tich hai ma tran----------\n\n";
                // SetColor(7);
                double mt1[50][50], mt2[50][50], mtkq[50][50];
                int sodong1, socot1, sodong2, socot2;
                matrix_2_input(mt1, mt2, sodong1, socot1, sodong2, socot2);
                if (socot1==sodong2){
                    matrix_mul(mt1, mt2, sodong1, socot1, socot2, mtkq);
                    matrix_1_output(mtkq, sodong1, socot2);
                }
                else cout << "Khong the tinh !!!\n"; 
                cout << "\n0. Tro ve\n1. Thu lai\nVui long lua chon: ";
                cin >> choice;
            }
            menu();
            break;
        }
        case 3:{
            choice=1;
            while (choice){
                system("cls");
                // SetColor(6);
                cout << "----------Tim nghich dao cua ma tran----------\n\n";
                // SetColor(7);
                double mt[50][50];
                int sodong, socot;
                matrix_1_input(mt, sodong, socot);
                if (sodong==socot){
                    matrix_inverse(mt, sodong);
                    if (matrix_check_identity(mt, sodong)){
                        matrix_1_output_begin_end(mt, 0, sodong, sodong, 2*sodong);
                    }
                    else cout << "Khong co ma tran nghich dao !!!";
                }
                else cout << "Ma tran kha nghich la ma tran vuong !!!";
                cout << "\n0. Tro ve\n1. Thu lai\nVui long lua chon: ";
                cin >> choice;
            }
            menu();
            break;
        }
        case 4:{
            choice=1;
            while (choice){
                system("cls");
                // SetColor(6);
                cout << "----------Tim hoan vi cua ma tran----------\n\n";
                // SetColor(7);
                double mt[50][50], mtkq[50][50];
                int sodong, socot;
                matrix_1_input(mt, sodong, socot);
                matrix_T(mt, sodong, socot, mtkq);
                matrix_1_output(mtkq, socot, sodong);
                cout << "\n0. Tro ve\n1. Thu lai\nVui long lua chon: ";
                cin >> choice;
            }
            menu();
            break;
        }
        case 5:{
            choice=1;
            while (choice){
                double mt[50][50];
                int an;
                system("cls");
                matrix_input_system(mt, an);
                matrix_system_solving(mt, an);
                if (matrix_check_identity(mt, an))
                    matrix_output_system(mt, an);
                else if (mt[an-1][an]==0) cout << "\nVo so nghiem !!!";
                    else cout << "\nVo nghiem !!!";
                cout << "\n0. Tro ve\n1. Thu lai\nVui long lua chon: ";
                cin >> choice;              
            }
            menu();
            break;
        }
        case 6:{
            choice=1;
            while (choice){
                double mt[50][50];
                int sodong, socot;
                system("cls");
                // SetColor(6);
                cout << "----------Tinh hang ma tran----------\n\n";
                // SetColor(7);
                matrix_1_input(mt, sodong, socot);
                cout << "\nHang ma tran la: ";
                cout << matrix_rank(mt, sodong, socot);
                cout << "\n0. Tro ve\n1. Thu lai\nVui long lua chon: ";
                cin >> choice;   
            }
            menu();
            break;
        }
        case 7:{
            choice=1;
            while (choice){
                double mt[50][50];
                int m;
                system("cls");
                // SetColor(6);
                cout << "----------Tinh dinh thuc cua ma tran----------\n\n";
                // SetColor(7);
                matrix_1_input(mt, m, m);
                cout << "\nKet qua: " << matrix_det(mt, m);
                cout << "\n0. Tro ve\n1. Thu lai\nVui long lua chon: ";
                cin >> choice;                  
            }
            menu();
            break;
        }
        default:{
            exit(0);
            break;
        }
    }

}