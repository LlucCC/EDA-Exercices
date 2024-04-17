#include<vector>
#include<iostream>
using namespace std;

typedef vector<vector<int>> Graph;



bool is_tree(const Graph& G, vector<bool>& visited, int v, int prev) {
    visited[v] = true;
    int edges = G[v].size();
    for (int i = 0; i < edges; ++i) {
        if (G[v][i] != prev) {
            if (visited[G[v][i]]) return false;
            if (not is_tree(G, visited, G[v][i], v)) return false;
        }
    }
    return true;
}

int tree_num(Graph& G) {
    int count = 0;
    int vnum = G.size();
    vector<bool> visited(vnum, false);
    for (int i = 0; i < vnum; ++i) {
        if (not visited[i]) {
            if (is_tree(G, visited, i, i)) ++count;
            else return 0;
        }
    }
    return count;
}

void Graph_init(int m, Graph& G) {
    for (int i = 0; i < m; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            G[v1].push_back(v2);
            G[v2].push_back(v1);
        }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        Graph_init(m, G);
        int num = tree_num(G);
        if (num == 0) cout << "no" << endl;
        else cout << num << endl;
    }
}