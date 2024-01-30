#include <iostream>
using namespace std;
int main() {
    int a = 16777216;
    float b = 16777216;
    int c = 16777217;
    assert(a == b && b == c);
    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
    return 0;
}
