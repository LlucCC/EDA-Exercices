#include<vector>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef vector<vector<char>> Graf;
typedef vector<vector<int>> Visitats;
int m;
int n;

void grafs_init(Graf& G, Visitats& V) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> G[i][j];
            if (G[i][j] == 'X') V[i][j] = -2;
            else V[i][j] = -1; 
        }
    }
}


int BFS(const Graf& G, Visitats& V, int r, int c) {
    queue<pair<int, int>> Q;
    stack<int> dist;
    Q.push(make_pair(r, c));
    V[r][c] = 0;
    while(not Q.empty()) {
        pair<int, int> act = Q.front(); 
        Q.pop();
        //cout << "Posició actual: " << act.first << " " << act.second << " Distancia: " << V[act.first][act.second] << endl;
        if (G[act.first][act.second] == 't') dist.push(V[act.first][act.second]);
        if ((act.first + 1 < G.size()) and V[act.first + 1][act.second] == -1) {
            Q.push(make_pair(act.first + 1, act.second));
            V[act.first + 1][act.second] = V[act.first][act.second] + 1;
        }
        if ((act.first - 1 >= 0) and V[act.first - 1][act.second] == -1) {
            Q.push(make_pair(act.first - 1, act.second));
            V[act.first - 1][act.second] = V[act.first][act.second] + 1;
        }
        if ((act.second + 1 < G[act.first].size()) and V[act.first][act.second + 1] == -1) {
            Q.push(make_pair(act.first, act.second + 1));
            V[act.first][act.second + 1] = V[act.first][act.second] + 1;
        }
        if ((act.second - 1 >= 0) and V[act.first][act.second - 1] == -1) {
            Q.push(make_pair(act.first, act.second - 1));
            V[act.first][act.second - 1] = V[act.first][act.second] + 1;
        }
    }
    if (dist.empty()) return -1;
    else return dist.top();

}

int main() {
    int r, c;
    cin >> n >> m;  
    Graf G(n, vector<char> (m));  
    Visitats V(n, vector<int> (m));
    grafs_init(G, V);
    cin >> r >> c;
    --r;
    --c;
    int mind = BFS(G, V, r, c);
    if (mind == -1) cout << "no treasure can be reached" << endl;
    else cout << "maximum distance: " << mind << endl;
}