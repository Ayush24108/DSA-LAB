#include <iostream>
using namespace std;



void createSparse(int A[10][10], int m, int n, int sparse[100][3]) {
    int count = 1; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = A[i][j];
                count++;
            }
        }
    }
    sparse[0][0] = m;
    sparse[0][1] = n;
    sparse[0][2] = count - 1; 
}


void print(int A[100][3]) {
    
    for (int i = 0; i <= A[0][2]; i++) {
        cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl;
    }
}




void transpose(int sparse[100][3], int trans[100][3]) {
    int row = sparse[0][0];
    int col = sparse[0][1];
    int elements = sparse[0][2];

    trans[0][0] = col;
    trans[0][1] = row;
    trans[0][2] = elements;

    int count = 1;
    for (int i = 0; i < col; i++) {
        for (int j = 1; j <= elements; j++) {
            if (sparse[j][1] == i) {
                trans[count][0] = sparse[j][1];
                trans[count][1] = sparse[j][0];
                trans[count][2] = sparse[j][2];
                count++;
            }
        }
    }
}


void Addition(int SparseA[100][3], int SparseB[100][3], int add[100][3]) {
    int row = SparseA[0][0];
    int col = SparseB[0][1];

    

    int temp[100][100]={0} ;  

   
    for (int i = 1; i <= SparseA[0][2]; i++) {
        temp[SparseA[i][0]][SparseA[i][1]] = SparseA[i][2];
    }

    
    for (int i = 1; i <= SparseB[0][2]; i++) {
        temp[SparseB[i][0]][SparseB[i][1]] += SparseB[i][2];
    }

    
    int count = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (temp[i][j] != 0) {
               add[count][0] = i;
                add[count][1] = j;
                add[count][2] = temp[i][j];
                count++;
            }
        }
    }

   add[0][0] = row;
    add[0][1] = col;
   add[0][2] = count- 1;
}



void Multiplication(int SparseA[100][3], int SparseB[100][3], int result[100][3]) {
    

    int row = SparseA[0][0];
    int col = SparseB[0][1];
    int elements1 = SparseA[0][2], elements2 = SparseB[0][2];

    int temp[100][100]={0}; 

    
    for (int i = 1; i <= elements1; i++) {
        for (int j = 1; j <= elements2; j++) {
            if (SparseA[i][1] == SparseB[j][0]) {
                temp[SparseA[i][0]][SparseB[j][1]] += SparseA[i][2] * SparseB[j][2];
            }
        }
    }


    int count = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (temp[i][j] != 0) {
                result[count][0] = i;
                result[count][1] = j;
                result[count][2] = temp[i][j];
                count++;
            }
        }
    }
    result[0][0] = row;
    result[0][1] = col;
    result[0][2] = count - 1;
}


int main() {
    int A[10][10], B[10][10];
    int m, n;

    cout << "Enter rows and cols of matrices";
    cin >> m >> n;

    cout << "Enter elements of matrix A"<<endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of matrix B"<<endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    int SparseA[100][3];


    createSparse(A, m, n, SparseA);
    
    
    cout<<"Sparsed matriX A is "<<endl;
    print(SparseA);
     
    int SparseB[100][3];

    createSparse(B, m, n, SparseB);

     

    cout<<"Sparsed matriX B is "<<endl;
     print(SparseB);

  
     int trans[100][3];

    transpose(SparseA, trans);
      
    cout<<"Transposed sparse matrix is"<<endl;
    print(trans);

   int add[100][3];
    
   Addition(SparseA, SparseB, add);

   cout<<"Addition of matrices is"<<endl;
    print(add);

  int mul[100][3];

  Multiplication(SparseA, SparseB, mul);


    cout << "Multiplication of matrices is"<<endl; 
    print(mul);

  
}
