#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

typedef vector<vector<int>> Graph;
int n;

void print_sol(vector<int>& sol) {
    for (int i = 0; i < n; ++i) {
        cout << sol[i];
        if (i != n - 1) cout << " ";
        else cout << endl;
    }
}   

void topological_orderings_rec(Graph& G, vector<int>& ge,vector<bool>& V, vector<int>& sol, set<int>& S, int p) {    
    if(p == n) print_sol(sol);
    else {
        set<int>::iterator it = S.begin();
        while (it != S.end()) {
            int act = *it;
            for (int i = 0; i < G[act].size(); ++i) {
                --ge[G[act][i]];
                if (ge[G[act][i]] == 0) S.insert(G[act][i]);
            }
            sol[p] = act;
            S.erase(it);
            topological_orderings_rec(G, ge, V, sol, S, p + 1);
            for (int i = 0; i < G[act].size(); ++i) {
                if (ge[G[act][i]] == 0) S.erase(G[act][i]);
                ++ge[G[act][i]];
            }
            it = S.insert(act).first;
            ++it;
        }
    }
}

void topological_orderings(Graph& G, vector<int>& ge) {
    vector<bool> V(n, false);
    vector<int> sol(n);
    set<int> S;
    for (int i = 0; i < n; ++i) {
        if (ge[i] == 0 and not V[i]) S.insert(i);
    }
    topological_orderings_rec(G, ge, V, sol, S, 0);
}

int main() {
    int m;
    cin >> n >> m;
    vector<int> ge(n, 0);
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; 
        G[u].push_back(v);
        ++ge[v];    
    }
    topological_orderings(G, ge);
}