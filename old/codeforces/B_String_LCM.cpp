#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool divide(const std::string& q, const std::string& n) {
    if (q.size() == 0) {
        return true;
    }
    if (n.size() % q.size() != 0) {
        return false;
    }
    int b = n.size() / q.size();
    for (int i = 0; i < n.size(); ++i) {
        if (n[i] != q[i % q.size()]) {
            return false;
        }
    }
    return true;
}

// a >= b
std::string gcd(const std::string& a, const std::string& b) {
    if (a.size() < b.size()) {
        return gcd(b,a);
    }
  
    std::string out;
    for (int i = 1; i <= b.size(); ++i) {
        string q = b.substr(0, i);
        if (divide(q, a) && divide(q, b)) {
            out = q;
        }
    }
    return out;
}

int gcd(int a, int b){
    if (b == 0)
       return a;
    return gcd(b, a % b); 
}

int main() {
    int q;
    cin >> q;
    while(q--){
        std::string s,t; 
        cin >> s >> t;
        auto g = gcd(s,t);
        if (g == "") {
            cout << -1 << endl;
            continue;
        }

        auto len = s.size() * t.size() / gcd(s.size(), t.size());
        auto tt = len / g.size();
        while(tt--) {
            cout << g;
        }
        cout << endl;
    }
}