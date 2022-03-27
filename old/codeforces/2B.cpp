#include <iostream>
#include <algorithm>
#include <vector>

#define For(i,s,n) for(int i =(s); i < (n); ++i)
#define ll long long

using namespace std;

template <typename T,typename U>                                                   
pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
} 

int n_of_factor(int n, int f) {
    int out = 0;
    while(n % f == 0) {
        n /= f;
        ++ out;
    }
    return out;
}

pair<int, int> twos_fives(int n) {
    return pair<int, int>(n_of_factor(n,2), n_of_factor(n,5));
}

int tens(pair<int, int> p) {
    return min(p.first, p.second);
}

void go(int i, int j, int p, int q) {
	while (i!=p) printf("D"), ++i;
	while (j!=q) printf("R"), ++j;
}

int main() {
    int n;
    cin >> n;

    int zi, zj;
    bool zero = false;
    auto num = vector< vector< pair<int, int> > >(n+1, vector< pair<int, int> >(n+1));
    auto dp = vector< vector< pair<int, int> > >(n+1, vector< pair<int, int> >(n+1, make_pair(60,60)));
    auto ch = vector< vector< char > >(n+1, vector<char>(n+1));
    For(i, 1, n+1)
        For(j, 1, n+1) {
            int t;
            cin >> t;
            if (t == 0) zero = true, zi = i, zj = j;
            else num[i][j] = twos_fives(t);
        }

    dp[0][1] = make_pair(0,0);
    For(i, 1, n + 1)
        For(j, 1, n + 1) {
            auto c1 = dp[i][j-1] + num[i][j];
            auto c2 = dp[i-1][j] + num[i][j];
            if(tens(c1) == tens(c2)) {
                if (c1 < c2) {
                    ch[i][j] = 'R';
                    dp[i][j] = c1;
                } else {
                    ch[i][j] = 'D';
                    dp[i][j] = c2;
                }
            } else if(tens(c1) < tens(c2)) {
                ch[i][j] = 'R';
                dp[i][j] = c1;
            } else {
                ch[i][j] = 'D';
                dp[i][j] = c2;
            }
        }
    
    int i = n, j = n;
    if (zero && tens(dp[i][j]) >= 1) {
        cout << 1 << endl;
        go(1, 1, zi, zj);
        go(zi, zj, n-1, n-1);
        return 0;
    }
    cout << tens(dp[i][j]) << endl;
    string str;
    while(i > 1 || j > 1) {
        if(ch[i][j] == 'D') {
            str += 'D';
            --i;
        } else {
            str += 'R';
            --j;
        }
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}