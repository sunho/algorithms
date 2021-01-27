#include <iostream>
#include <algorithm>

using namespace std;

// x on y = sum (for each x_i, |{x_i > y_i}|)
// inv(seq) = # of inversion in seq
// Conjecture 1 (TODO prove this)
// For n = 2k -1 case
// # of inversion is constant
// 1 2 3 2 1
//   Further:
//    inv (1 2 3 2 1) = inv (1 2 3)  + inv (3 2 1) + 1,2 on 2, 1
//    inv (1 2 3) + inv (3 2 1) = constant (need to prove)
//    1, 2 on 2, 1 will always be constant b.c.
//    1 2 | 3 | 2 1
//     x         y
//    x and y is from same set (sort(x) = sort(y))
//
// Assume conjecture 1 is true,
// for n != 2k - 1 case
// We can separate out "pivot" part and use conjecture 1 on remaining part.
// 1 | 2 3 4 3 2 
// ^ pivot    ^ remainging
// inv (remaining) = constant (conjecture 1)
// inv (whole) = pivot on remaining + inv (remaining) + inv (pivot)
// pivot on remaining is the dominating term
// Expanding conjecture 1: this should hold true even if the elements are not 1, 2, 3, ...
///  Since, set of elements from the subsection of 1,2,3, ... will be totally ordered
//   (e.g. 1, 3, 4)
//   inv (1, 3, 4) + inv(4, 3, 1) = constant
// Pivot on remaning is minimum when pivot is 1, 2, 3 .... 
//  since x on y is decided by | {x_i > y_i} | so we want x_i as small as possible plus inv (pivot) = 0
// However, inv(whole) should not exceed inv(1,2,3,2,...) 
//  meaning inv(1,2,3,2,...) is actually the minimum # of inversion possible 
// Summing up, we want pivot part to be (size: 2*k-n-1) 1,2,3, ... 
// For remaining part, we can do wathever we want, 
// so we can just maximize lexicographicality by chosing the largest value possible every time.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int p = 2*k-n-1;
        // pivot part 1,2,3, ...
        for (int i = 1; i <= p; ++i) {
            cout << i << " ";
        }
        // lexicographicallity maximization
        for (int i = k; i > p; --i) {
            cout << i << " ";
        }
        cout << endl;
    }
}