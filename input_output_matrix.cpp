#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

// void SetColor(int ForgC)
// {
//     WORD wColor;
//     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     // We use csbi for the wAttributes word.
//     if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
//     {
//         // Mask out all but the background attribute, and add in the foreground color
//         wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
//         SetConsoleTextAttribute(hStdOut, wColor);
//     }
//     return;
// }

void matrix_1_input(double a[50][50], int &m, int &n)
{
    cout << "Vui long nhap kich thuoc ma tran thu theo dang m n: ";
    cin >> m >> n;
    cout << "Vui long nhap cac gia tri trong ma tran: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void matrix_2_input(double a1[50][50], double a2[50][50], int &m1, int &n1, int &m2, int &n2)
{
    cout << "Vui long nhap kich thuoc ma tran thu nhat theo dang m n: ";
    cin >> m1 >> n1;
    cout << "Vui long nhap cac gia tri trong ma tran A: " << endl;
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            cin >> a1[i][j];
        }
    }
    cout << "\nVui long nhap kich thuoc ma tran thu hai theo dang m n: ";
    cin >> m2 >> n2;
    cout << "Vui long nhap cac gia tri trong ma tran B: " << endl;
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> a2[i][j];
        }
    }
}

void matrix_1_output(double a[50][50], int m, int n)
{
    cout << "\nKet qua: \n";
    for (int i = 0; i < m; i++)
    {
        cout << "| ";
        for (int j = 0; j < n; j++)
        {
            printf("%5.1f", a[i][j]);
        }
        cout << " |\n";
    }
}

void matrix_1_output_begin_end(double a[50][50], int ybegin, int xbegin, int yend, int xend)
{
    cout << "\nKet qua: \n";
    for (int i = ybegin; i < yend; i++)
    {
        cout << "| ";
        for (int j = xbegin; j < xend; j++)
        {
            printf("%5.1f", a[i][j]);
        }
        cout << " |\n";
    }
}

void matrix_input_system(double a[50][50], int &rank)
{
    // SetColor(6);
    cout << "----------Giai he phuong trinh----------\n\n";
    // SetColor(7);
    cout << "Vui long nhap so an cua he phuong trinh: ";
    cin >> rank;
    cout << "He phuong trinh co dang: \n";
    for (int i = 0; i < rank; i++)
    {
        char ope = '+';
        for (int j = 0; j < rank; j++)
        {
            if (j == rank - 1)
                ope = ' ';
            // SetColor(6);
            cout << (char)(j + 97) << i + 1;
            // SetColor(7);
            cout << "*x" << j + 1 << " " << ope << " ";
        }
        cout << "= ";
        // SetColor(6);
        cout << (char)(i + 65) << "\n";
    }
    // SetColor(7);
    cout << "Vui long nhap cac he so theo thu tu cac dong va cot: \n";
    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank + 1; j++)
        {
            cin >> a[i][j];
        }
    }
}

void matrix_output_system(double a[50][50], int rank)
{
    cout << "\nKet qua:\n";
    for (int i = 0; i < rank; i++)
    {
        cout << "x" << i + 1 << " = " << a[i][rank] << endl;
    }
}
