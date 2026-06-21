#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

/*this function takes number of rows and columns from the user
and then takes the elements from the users as inputs*/

void inputMatrix(int M[MAX][MAX], int& rows, int& cols, char name) {
    cout << "\nEnter rows for Matrix " << name << ": ";
    cin >> rows;
    cout << "Enter columns for Matrix " << name << ": ";
    cin >> cols;

    cout << "Enter elements of Matrix " << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> M[i][j];
        }
    }
}
/*this function displays the matrix*/
void printMatrix(int M[MAX][MAX], int rows, int cols, string title) {
    cout << "\n" << title << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
/*validates number of rows and columns to perform addition and subtraction*/
bool canAdd(int r1, int c1, int r2, int c2) {
    return (r1 == r2 && c1 == c2);
}
/*validates inputs(no.of rows and coloumns) for multiplication*/
bool canMultiply(int c1, int r2) {
    return (c1 == r2);
}
// addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}
//subtraction
void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            R[i][j] = A[i][j] - B[i][j];
        }
    }
}
//multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX],
    int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
//main
int main() {

    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    int r1, c1, r2, c2;

    int choice;
// menu
    while (true) {
        cout << "\n===== Matrix Calculator =====\n";
        cout << "1. Input Matrix A\n";
        cout << "2. Input Matrix B\n";
        cout << "3. Display Matrices\n";
        cout << "4. Add (A + B)\n";
        cout << "5. Subtract (A - B)\n";
        cout << "6. Multiply (A * B)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1:
            inputMatrix(A, r1, c1, 'A');
            break;

        case 2:
            inputMatrix(B, r2, c2, 'B');
            break;

        case 3:
            printMatrix(A, r1, c1, "Matrix A");
            printMatrix(B, r2, c2, "Matrix B");
            break;

        case 4:
            if (canAdd(r1, c1, r2, c2)) {
                addMatrix(A, B, R, r1, c1);
                printMatrix(R, r1, c1, "A + B");
            }
            else {
                cout << "Addition not possible (sizes not equal)!\n";
            }
            break;

        case 5:
            if (canAdd(r1, c1, r2, c2)) {
                subtractMatrix(A, B, R, r1, c1);
                printMatrix(R, r1, c1, "A - B");
            }
            else {
                cout << "Subtraction not possible (sizes not equal)!\n";
            }
            break;

        case 6:
            if (canMultiply(c1, r2)) {
                multiplyMatrix(A, B, R, r1, c1, c2);
                printMatrix(R, r1, c2, "A * B");
            }
            else {
                cout << "Multiplication not possible!\n";
            }
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    cout << "Goodbye!\n";
    system("pause");
    return 0;
}