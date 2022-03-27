#include <iostream>
using namespace std;




int main() {
    int t;
    cin >> t;
    for (int l = 0; l < t; ++l) {
        int x;
        cin >> x;

        std::string out = "";
        for (int i = 9; i >= 1; --i) {
            if (i <= x) {
                out = to_string(i) + out;
                x -=i;
            }
        }
        if (x!=0) {
            cout << "-1" << endl;
        } else {
            cout << out << endl;
        }
    }
}