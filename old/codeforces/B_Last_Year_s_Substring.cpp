#include <iostream>

using namespace std;
//20/20
//2/020
//202/0
//2020

bool check(std::string s) {
    if (s.size() == 4 && s == "2020") {
        return true;
    }
    if (s.size() >= 4) {
        if (s.substr(0,4) == "2020") {
            return true;
        } 
        
        if (s.substr(s.size() - 4) == "2020") {
            return true;
        }

        if (s.substr(0, 1) == "2" && s.substr(s.size() - 3) == "020") {
            return true;
        }
        
        if (s.substr(0, 2) == "20" && s.substr(s.size() - 2) == "20") {
            return true;
        }

        if (s.substr(0, 3) == "202" && s.substr(s.size() - 1) == "0") {
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        std::string s;
        cin >> s;
        if (check(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}