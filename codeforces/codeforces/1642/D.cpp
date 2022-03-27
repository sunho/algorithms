#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi A(n);
        for(int i=0;i<n;i++) cin >> A[i];
        map<int, int> nums;
        for(int i=0;i<n;i++) {
            nums[A[i]]++;
        }
        bool okay = true;
        vector<int> ten2;
        for (auto& x:nums) {
            if (x.second % 2 == 1) {
                okay = false;
            }
            ten2.push_back(x.second);
        }
        if (!okay) {
            cout << -1 << '\n';
            continue;
        }
        int k = 0; // inserted place
        vector<int> ten;
        vector<pii> ans;
        for(int i=0;i<n;i++) {
            auto it = nums.end();
            it--;
            if (A[n-i-1] == it->first) {
                it->second--;
            } else {
                it->second--;
                int j;
                for(j=0;j<n-i;j++) {
                    if (A[j] == it->first) {
                        break;
                    }
                }
                for(int z=0;z<=j;z++) {
                    ans.push_back({k+j+z, A[z]});
                }
                reverse(A.begin(), A.begin()+j+1);
                k+=2*(j+1);
                ten.push_back((j+1)*2);
                for(int z=0;z<(n-i);z++) {
                    ans.push_back({k+(n-i)+z-1, A[z]});
                }
                k+=2*(n-i);
                ten.push_back((n-i)*2);
                reverse(A.begin(), A.begin()+(n-i));

            }
            if (it->second == 0) nums.erase(it);
        }
        ten.insert(ten.end(), ten2.begin(), ten2.end());
        cout << ans.size() << '\n';
        for (auto& x:ans) {
            cout << x.first+1 << " " << x.second << '\n';
        }
        cout << ten.size() << '\n';
        for (auto& x:ten) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}