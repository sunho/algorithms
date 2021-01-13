#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h> 

using namespace std;

int N;
int K;
double dists[100] = {0};

double obj_prob(int i, double r) {  
    if (dists[i] <= r) {
        return 1.0;
    }
    return exp(1-(pow(dists[i], 2.0)/pow(r, 2.0)));
}

double distance(int x0, int y0, int x1, int y1) {
    return sqrt(pow(x1-x0, 2) + pow(y1-y0, 2));
}

// p(i, k) k successes
// p(0, 0) = 1-p(d_0,r)
// p(0, 1) = p(d_0,r)
// p(1, 0) = p(0, 0) * (1-p(d_1,r))
// p(1, 1) = p(0, 1) * (1-p(d_1,r)) + p(0, 0) * p(d_1,r)
// p(1, 2) = p(0, 1) * p(d_1,r)
// p(i, k) = p(i-1,k-1) * p(d_i,r) + p(i-1,k) * (1-p(d_i,r))
// p(i, k) = 0 if k out of bound (0 < i <= k - 1)

double caclulate_prob(double r) {
    double probs[100];
    for (int i = 0; i < N; ++i) {
        probs[i] = obj_prob(i, r);
    }

    double dp[100][101] = {0};
    dp[0][0] = 1.0-probs[0];
    dp[0][1] = probs[0];
    for (int i = 1; i < N; ++i) {
        for (int k = 0; k <= i + 1; ++k) {
            dp[i][k] = 0.0;
            if (k >= 1) {
                dp[i][k] += dp[i-1][k-1] * probs[i];
            }
            if (k <= i) {
                 dp[i][k] += dp[i-1][k] * (1-probs[i]);
            }
        }
    }


    double out = 0.0;
    for (int i = K; i <= N; ++i) {
        out += dp[N-1][i];
    }

    return out;
}

int main() {
	cin >> N;


    cin >> K;


    int e;
    cin >> e;
    
    double ee = e / 1000.0;

    int x0, y0;

    cin >> x0 >> y0;

    for (int i = 0; i < N; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        dists[i] = distance(x0,y0,xi,yi);
    }

    double left = 0.0;
    double right = 10000.0;
    // -       +
    // if prob > 1 - e go to - (slice right)
    // else go to + (slice left)
    // |   *   |
    double lastp = 0.0;
    double r;
    while(true) {
        r = (right + left)/2.0;
        double p = caclulate_prob(r);
        if (p >= 1 - ee) {
            right = r;
        } else {
            left = r;
        }

        if (right - left <= 0.0000001) {
            break;
        }
    }

    cout.precision(17);
    cout << r << endl;

	return 0;
}