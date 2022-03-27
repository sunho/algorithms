#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define x first
#define y second
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define trav(x,a) for(auto& x : (a))
#define endl '\n'
template<class T> bool ckmin(T&a, const T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, const T&b) { bool B = a < b; a = max(a,b); return B; }
template <typename T,typename U> pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) { return {l.first+r.first,l.second+r.second}; }

template<typename U = unsigned, int B = 32>
class binary_trie {
    struct node {
        int cnt;
        node *ch[2];
        node() : cnt(0), ch{ nullptr, nullptr } {}
    };
    node* add(node* t, U val, int b = B - 1) {
        if (!t) t = new node;
        t->cnt += 1;
        if (b < 0) return t;
        bool f = (val >> (U)b) & (U)1;
        t->ch[f] = add(t->ch[f], val, b - 1);
        return t;
    }
    node* sub(node* t, U val, int b = B - 1) {
        assert(t);
        t->cnt -= 1;
        if (t->cnt == 0) return nullptr;
        if (b < 0) return t;
        bool f = (val >> (U)b) & (U)1;
        t->ch[f] = sub(t->ch[f], val, b - 1);
        return t;
    }
    U get_min(node* t, U val, int b = B - 1) const {
        assert(t);
        if (b < 0) return 0;
        bool f = (val >> (U)b) & (U)1; f ^= !t->ch[f];
        return get_min(t->ch[f], val, b - 1) | ((U)f << (U)b);
    }
    U get(node* t, int k, int b = B - 1) const {
        if (b < 0) return 0;
        int m = t->ch[0] ? t->ch[0]->cnt : 0;
        return k < m ? get(t->ch[0], k, b - 1) : get(t->ch[1], k - m, b - 1) | ((U)1 << (U)b);
    }
    int count_lower(node* t, U val, int b = B - 1) {
        if (!t || b < 0) return 0;
        bool f = (val >> (U)b) & (U)1;
        return (f && t->ch[0] ? t->ch[0]->cnt : 0) + count_lower(t->ch[f], val, b - 1);
    }
    node *root;
public:
    binary_trie() : root(nullptr) {}
    int size() const {
        return root ? root->cnt : 0;
    }
    bool empty() const {
        return !root;
    }
    void insert(U val) {
        root = add(root, val);
    }
    void erase(U val) {
        root = sub(root, val);
    }
    U max_element(U bias = 0) const {
        return get_min(root, ~bias);
    }
    U min_element(U bias = 0) const {
        return get_min(root, bias);
    }
    int lower_bound(U val) { // return id
        return count_lower(root, val);
    }
    int upper_bound(U val) { // return id
        return count_lower(root, val + 1);
    }
    U operator[](int k) const {
        assert(0 <= k && k < size());
        return get(root, k);
    }
    int count(U val) const {
        if (!root) return 0;
        node *t = root;
        for (int i = B - 1; i >= 0; i--) {
            t = t->ch[(val >> (U)i) & (U)1];
            if (!t) return 0;
        }
        return t->cnt;
    }
};
 
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int t;
    cin >> t;

    while(t--) {
        binary_trie<int> tri;
        int l,r;
        cin >> l >> r;
        int n = r-l+1;
        vi B(n);
        vi cnds;
        rep(i,0,n) {
            cin >> B[i];
            tri.insert(B[i]);
            cnds.push_back(B[i] ^ l);
        }
        sort(all(cnds));
        int ans = -1;
        trav(x, cnds) {
            if ((tri.max_element(x)^x) == r && (tri.min_element(x)^x) == l) {
                ans = x;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
