#include <iostream>

using namespace std;


int main() {
    int n, x, pos;
    cin >> n >> x >> pos;

    int left, right;
    left = 0;
    right = n;
    int nless = 0;
    int nmore = 0;

    while (left < right) {
        int middle = (left + right) / 2;
        if (middle <= pos) {
            left = middle + 1;
            if (middle != pos) {
                nless ++;
            } 
        } else {
            right = middle;
            nmore ++;
        }
    }

    long long totalcands = n - 1;
    long long lesscands = x - 1;
    long long morecands = n - x;
    long long solution = 1;
    for (; totalcands > 0;) {
        if (nless > 0) {
            if (lesscands == 0) {
                solution = 0;
                break;
            }
            solution *= lesscands;
            lesscands --;
            nless --;
        } else if (nmore > 0) {
            if (morecands == 0) {
                solution = 0;
                break;
            }
            solution *= morecands;
            morecands --;
            nmore --;
        } else {
            solution *= totalcands;
        }
        totalcands --;
        solution = solution % 1000000007;
    }
    cout << solution << endl;
    return 0;
}