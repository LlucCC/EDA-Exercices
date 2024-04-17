#include<iostream>
#include<vector>
using namespace std;

int inversions_rec(vector<int>& V, int i, int j) {
    if (i >= j) return 0;
    int m = (i + j)/2;
    int n1 = inversions_rec(V, i, m);
    int n2 = inversions_rec(V, m + 1, j);
    int r = n1 + n2;

    vector<int> aux(j - i + 1);
    int k = 0;
    int p = i;
    int l = m + 1;
    while (i <= m and l <= j) {
        //cout << i << " " << j << " " << V[i] << " " << V[l] << " " << r << endl;
        if (V[i] <= V[l]) {
            aux[k] = V[i];
            ++i;
        }
        else {
            //cout << "jiji: " << m << " " << i << endl; 
            aux[k] = V[l];
            r += (m - i) + 1;
            ++l;
        }
        ++k;
    }
    while (i <= m) {
        aux[k] = V[i];
        ++i;
        ++k;
    }
    while (l <= j) {
        aux[k] = V[l];
        ++l;
        ++k;
    }
    for (int o = 0; o < (j - p + 1); ++o) {
        V[p + o] = aux[o];
        //cout << aux[o] << " ";
    }

    return r;
}

int inversions(vector<int>& V) {
    return inversions_rec(V, 0, V.size() - 1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        cout << inversions(V) << endl;
    }
}