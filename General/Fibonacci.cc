#include<vector>
#include<iostream>
using namespace std;

typedef vector< vector<int> > Matrix;

Matrix operator %(const Matrix& M, int m) {
    int size = M.size();
    Matrix R(size, vector<int> (size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            R[i][j] = M[i][j]%m;
        }
    }
    return R;
}

Matrix operator *(const Matrix& M, const Matrix& N) {
    int n = M.size();
    Matrix R(n, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            R[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                R[i][j] += M[i][k]*N[k][j];
            }
        }
    }
    return R;
}

void printMatrix(const Matrix& M) {
    int n = M.size();
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << M[i][j];
            if (j != n - 1) cout << " ";
        }  
        cout << endl;
    }
    cout << "----------" << endl;
}

Matrix modular_exp(const Matrix& M, int n, int m) {
    Matrix R(2, vector<int> (2));
    if (n == 0) {
        R[0][0] = 1;
        R[1][1] = 1;
        R[0][1] = 0;
        R[1][0] = 0;
        return R;
    }
    R =  modular_exp(M, n/2, m);
    R = R*R;
    R = R%m;
    if (n%2 == 0) return R%m;
    else return (M*R)%m;
}

void fiboMatrix_init(Matrix& M) {
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 1;
    M[1][1] = 0;
}

int main() {
    Matrix M (2, vector<int> (2));
    fiboMatrix_init(M);
    Matrix R;
    int n, m;
    while (cin >> n >> m) {
        if (n == 0) cout << "0" << endl;
        else {
            R = modular_exp(M, n - 1, m);
            cout << R[0][0] << endl;
        }
    }
