#include<iostream>
#include<vector>
using namespace std;

int max_guany (const vector<int>& p, int k) {
    int c = 0;
    int v = k;
    int n = p.size();
    for (int i = 1; i <= k; ++i) if (p[i] < p[c]) c = i;
    for (int i = k + 1; i  < n; ++i) if (p[i] > p[v]) v = i;
    cout << c << " " << v << endl;
    return (p[v]- p[c]);
}

int main() {
    vector<int> v(20);
    for (int i = 0; i < 20; ++i) v[i] = rand()%100;
    for (int i = 0; i < 20; ++i) cout << v[i] << " ";
    cout << endl;
    int k;
    cin >> k;
    cout << max_guany(v, k) << endl;
}