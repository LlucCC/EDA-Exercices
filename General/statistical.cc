#include<iostream>
#include<map>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    map<int, int> nums;
    string s;
    int n;
    double avg = 0;
    int total = 0;
    int totaln = 0;
    while (cin >> s) {
        if (s == "number") {
            cin >> n;
            ++nums[n];    
            total += n;
            ++totaln;
        }
        else if (s == "delete") {
            if (not nums.empty()) {
                auto it = nums.begin(); // set<int>
                --(it -> second);
                total -= it -> first;
                if (it -> second == 0) nums.erase(it);
                --totaln;
            }
        }
        avg =  double(total)/double(totaln);
        if (not nums.empty()) cout << "minimum: " << nums.begin() -> first << ", maximum: " << (--nums.end()) -> first << ", average: " << avg << endl;
        else cout << "no elements" << endl;
    }
}