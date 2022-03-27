#include <iostream>


using namespace std;

int main() {
    int t;
    cin >> t;

    int b[301];

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> b[j];
        }
        for (int j = 0; j < n; ++j) {
            if (j % 2 == 0) {
                cout << b[j / 2] << " ";
            } else {
                cout << b[n - j/2 - 1] << " ";
            }
        }
        cout << endl;
    }

}