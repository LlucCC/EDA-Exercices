#include<vector>
#include<iostream>
#include<queue>
#include<list>
#include<map>
using namespace std;

typedef map<string, vector<string>> Graph;

void Graph_init(Graph& G, int n, map<string, int>& ge) {
    string s1, s2;
    for (int i = 0; i < n; ++i) {
        cin >> s1;
        G.insert(make_pair(s1, vector<string>()));
        ge.insert(make_pair(s1, 0));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s1 >> s2;
        G[s1].push_back(s2);
        ++ge[s2];
    }
}

void print_list(const list<string>& L) {
    list<string>::const_iterator it = L.begin();
    while (it != L.end()) {
        cout << *it;
        ++it;
    }
    cout << endl;
}

bool task_ordering(const Graph& G, list<string>& L, map<string, int>& ge) {
    priority_queue<string, vector<string>, greater<string>> PQ;
    map<string, int>::iterator it = ge.begin();
    while (it != ge.end()) {
        if (it -> second == 0) PQ.push(it -> first);
        ++it;
    } 
    while (not PQ.empty()) {
        
        string act = PQ.top(); PQ.pop();
        L.push_back(act);
        ge.erase(act);

        auto actit = G.find(act);
        int size = (actit -> second).size();
        string next;
        
        for (int i = 0; i < size; ++i) {
            next = (actit -> second)[i];
            int temp = --ge[next];
            if (temp == 0) PQ.push(next);

        }
       
    }
    if (ge.empty()) return true;
    else return false;
}

int main() {
    int n;
    while(cin >> n) {
        map<string, int> ge;
        Graph G;
        Graph_init(G, n, ge); 
        list<string> L;
        bool valid = task_ordering(G, L, ge);
        if (valid) print_list(L);
        else cout << "NO VALID ORDERING" << endl;
    }
}