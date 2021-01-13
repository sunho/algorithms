

// for 2
// _   _ 
//   _
// w_n,1 = w_1,1(?) + w_1,2(?)


// for 3
// _ _ _
//  _ _
//   _

// w_1 = f(w_1, w_2)
// f(w_1, w_2) = f(f(w_1,w_2), f(w_2,w_3))
// f(w_1, w_2) = 터지는가? 

// Claim: (w_2 + w_1 or w_3 + w_1) or sum of all
// sum of all이 가능하면 무조건 노려야

// _ _ _ _
//  _ _ _
//   _ _
//    _

// f(i, k, amount) = f(i-1, k, ) 


#include <iostream>

using namespace std;

int N;
int a[50];
int w[50][51];

bool brute(int i, int k, int leftamount, int upamount) {
    brute(i+1, k, 0, upamount);
     
    
    for (int k = 0; k < N-i; ++k) {
        brute(i+1, )
    }
}

int main() {
    cin >> N;
    for (int i =0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N-i; ++j) {
            cin >> w[i][j];
        }
    }


}