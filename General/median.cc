#include<vector>
#include<iostream>
using namespace std;

int median_rec(int n, int l, int r, const vector<int>& b) {
    int m = (l + r)/2;
    if (b[m] >= n/2 and b[m-1] < n/2) return m;
    if (b[m] < n/2) return median_rec(n, m+1, r, b);
    return median_rec(n,l,m-1,b);
}


int median(int n, const vector<int>& b) {
    return median_rec(n, 0, b.size()-1, b);
}


int main() {
    int m;
    cin >> m;
    vector<int> a;
    int x;
    while (cin >> x)
    a.push_back(x);
    vector<int> b(m + 1, 0);
    int n = a. size ();
    for (int i = 0; i < n; ++i)
    ++b[ a[i] ];
    for (int j = 1; j <= m; ++j)
    b[j] += b[j - 1];
    cout << median(n, b);
}

