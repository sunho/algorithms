#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

// p = k*a q = k*b
// all possible moves can be represented by a grid.
// we can notice that if we divide the grid by a diogonal line, upper section and lower section are symmetric.
// that f(p,q) = f(q,p) where f is the solve function
// in other words, we can restrict the search space by a >= b
// then, notice that if one player tries to minimize the difference between a and b, 
// difference will be around 0 and 2
//    a, b, delta
// Ut 1, 0, 1
// As 1, 1, 0
// Ut 2, 1, 1
// As 2, 2, 0
// 
//    a, b, delta
// Ut 1, 0, 1
// As 2, 0, 2
// Ut 2, 1, 1
// As 3, 1, 2
// 
// Also, notice that if difference b.w. a and b is 0, (p,q) will be along the diagonal line
// this is where the a + b (turn) will be the largest.
// in other words, one can easily reach the last point along or near the diagonal line (pmax) by
// minimizing a - b
//
// and Ut wins if the a + b (turn) at the last point is even. and vice versa
// if the player knows that he wins if token reaches pmax, he can easily win by minimizing a - b
// in other words, the winner will be decided by maximum turn (tmax)
// 
// at pmax, a = b
// (k*a)^2 + (k*b)^2 = d^2
// a + b = sqrt(2) * d / k (tmax approx)
//
// notice
// a - b = a + b (mod 2)
// where a - b is the delta and a + b is the turn.
// a - b = 0 when tmax is even
//
// if the actual tmax is even, the point will be avaiable at (tmax/2, tmax/2) or (tmax/2-1, tmax/2-1)
// if actual tmax is odd, the point will be available at (tmax/2 - 1, tmax/2)

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll d, k;
        cin >> d >> k;
        ll tmax = sqrt(2) * d / k + 1;
        ll a = tmax / 2;
        ll b = tmax / 2;
        bool isa = false;
        if ((k*a)*(k*a) + (k*b)*(k*b) <= d*d) {
            isa = true;
        } else {
            --a;
            --b;
            if ((k*a)*(k*a) + (k*b)*(k*b) > d*d) {
                cout << "ERROR" << endl;
                return 0;
            }
            ++a;
            if ((k*a)*(k*a) + (k*b)*(k*b) <= d*d) {
                isa = false;
            } else {
                isa = true;
            }
        }
        if (!isa) {
            cout << "Ashish" << endl;
        } else {
            cout << "Utkarsh" << endl;
        }

    }
}