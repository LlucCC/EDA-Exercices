#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include<list>
using namespace std;

struct Component {
    string t;
    bool state;
    int nImputs;
    vector<bool> I;

    Component() {
        state = 0;
    }

    Component(string t1) {
        this -> t = t1;
        if (t == "INPUT") nImputs = 0;
        else if (this -> t == "NOT") nImputs = 1;
        else nImputs = 2;
    } 

    void set_type(string t1) {
        this -> t = t1;
        if (t == "INPUT") nImputs = 0;
        else if (this -> t == "NOT") nImputs = 1;
        else nImputs = 2;
    }

    void calculate_state() {
        if (t == "NOT") state = not I[0];
        else if (t == "AND") state = I[0] and I[1];
        else if (t == "OR") state = I[0] or I[1];
        else if (t == "XOR") state = (I[0] and not I[1]) or (I[1] and not I[0]); 
    }
};

typedef map<string, vector<string>> Graph;
map<string, Component> comps;

void getBool(bool& b) {
    string a;
    cin >> a;
    if (a == "T") b = true;
    else b = false;
}

void topological_sort(const Graph& G, map<string, int>& ge, string a) {
    bool b = true;
    stack<string> S;
    auto it1 = ge.begin(); 
    while (it1 != ge.end()) {
        if (it1 -> second == 0) S.push(it1 -> first);
        ++it1;
    }
    while (not S.empty()) {
        string act = S.top(); S.pop();
        bool in = comps[act].t == "INPUT";
        if (in and not b) getBool(comps[act].state); 
        else if (in) {
            if (a == "T") comps[act].state = true;
            else comps[act].state = false; 
            b = false;
        }
        map<string, vector<string>>::const_iterator it = G.find(act);
        int size = (it -> second).size();
        for (int i = 0; i < size; ++i) {
            string si = (it -> second)[i];
            comps[si].I.push_back(comps[act].state);
            int temp = --ge[si];
            if (temp == 0) {
                S.push(si);
                comps[si].calculate_state();
            }
        }
    }
}

void print_list(const list<string>& SL) {
    list<string>::const_iterator it = SL.begin();
    while (it != SL.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}


int main(){
    string s, res;
    map<string, int> ge;
    Graph G;
    cin >> res;
    cin >> s;
    vector<string> out;
    while (s != "END") {
        G.insert(make_pair(s, vector<string>()));
        ge[s] = 0;
        out.push_back(s);
        comps.insert(make_pair(s, Component("OUTPUT")));
        cin >> s;
    }
    cin >> res;
    cin >> s;
    while (s != "END") {
        G.insert(make_pair(s, vector<string>()));
        ge[s] = 0;
        comps.insert(make_pair(s, Component("INPUT")));
        cin >> s;
    }
    cin >> s;
    while (s != "END") {
        if (s == "NOT") {
            string s1, s2;
            cin >> s1 >> s2;
            G.insert(make_pair(s1, vector<string>()));
            G[s2].push_back(s1);
            comps[s1].t = s;
            ++ge[s1];
        }
        else {
            string s1, s2, s3;
            cin >> s1 >> s2 >> s3;
            G.insert(make_pair(s1, vector<string>()));
            G[s2].push_back(s1);
            G[s3].push_back(s1);
            comps[s1].t = s;
            ge[s1] += 2; 
        }
        cin >> s;
    }
    string a;
    while (cin >> a) {
        topological_sort(G, ge, a);
        int size = out.size();
        for (int i = 0; i < size; ++i) {
            if (comps[out[i]].state) cout << "T";
            else cout << "F";
            if (i == size - 1) cout << endl;
            else cout << " ";
        }
    }
    
}