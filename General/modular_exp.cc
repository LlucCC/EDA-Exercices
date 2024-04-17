#include<iostream>
using namespace std;

int mod_exp(int n, int k, int m) {
    if (k == 0) return n;
    int p = mod_exp(n, k/2, m);
    p = (p*p) % m;
    if (not (k % 2)) return p;
    else return (p*n)%m; 
}

int main() {
    int n, k, m;
    while (cin >> n >> k >> m) {
        n %= m;
        cout << mod_exp(n, k, m) << endl;
    }
}