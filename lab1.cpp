#include <iostream>

using namespace std;

void cmmdc(int m, int n, int* result){
    while(n!=0){
        int temp = n;
        n = m%n;
        m = temp;
    }

    *result = m;
}

int fibo_r(int n){
    if(n<2) return n;

    return fibo_r(n-1) + fibo_r(n-2);
}

void produs(int** A, int** B, int** C, int m, int n, int k){
    for(int i = 0; i< m; i++)
        for(int j = 0; j< k; j++)
            for(int l = 0; l< n; l++)
                C[i][j] += A[i][l]*B[l][j];
}

int main() {
    int m = 48;
    int n = 18;
    int result = 0;
    cmmdc(m, n, &result);
    cout<< "CMMDC: " << result << endl;

    //1. Declaram variabilele i,j,s,n
    int i = 0;
    int j = 1;
    int s = i + j; // int s = 1;
    n = 10;
    //2. Iteram cu for de la 0 la n
    for(int index = 0; index < n; index++){
        //3. Calculam noul element din sirul Fib
        i = j;
        j = s;
        s = i + j;
    }
    //4. Afisam valoarea finala
    cout<< "Fib de " << n << ": " << i <<endl;
    cout<< "Fib de " << n << ": " << fibo_r(n) <<endl;

    n = 2; // A 2x3
    m = 3; // B 3x2
    int k = 2; // C 2x2

    int** A = new int*[n];
    for(int i= 0; i < n; i++)
        A[i] = new int[m];

    int** B = new int*[m];
    for(int i= 0; i < m; i++)
        B[i] = new int[k];

    int** C = new int*[n];
    for(int i= 0; i < n; i++)
        C[i] = new int[k];

    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;

    B[0][0] = 7; B[0][1] = 8;
    B[1][0] = 9; B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;

    C[0][0] = 0; C[0][1] = 0;
    C[1][0] = 0; C[1][1] = 0;

    cout<<"A:"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout<<A[i][j]<< " ";
        cout<<endl;
    }

    cout<<"B:"<<endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++)
            cout<<B[i][j]<< " ";
        cout<<endl;
    }

    produs(A, B, C, n, m, k);

    cout<<"C:"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++)
            cout<<C[i][j]<< " ";
        cout<<endl;
    }

    return 0;
}
