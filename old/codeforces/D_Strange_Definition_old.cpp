#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <cmath>
#include <unordered_map>

#define endl '\n'
#define N 1000000
#define M 300000

using namespace std;
using ll = long long;
int output[M];
set<int> squares;

bool issquare(ll x)
{ 
    return squares.find(x) != squares.end();
}

int _gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return _gcd(b,a);
}

#define CACHE_SIZE 1000000

struct Node {
    ll key;
    int i;
    int value;
    Node* next;
    Node* prev;
};

Node* head;
Node* tail;
Node nodes[CACHE_SIZE];
unordered_map<ll, int> nodemap;

void front_node(Node* node) {
    if (node == head) return;
    if (node->next) {
        node->next->prev = node->prev;
        if (!node->prev) {
            tail = node->next;
        }
    }
    if (node->prev) {
        node->prev->next = node->next;
    }
    head->next = node;
    node->next = nullptr;
    head = node;
}

void add_node(ll key, int value) {
    int newi = nodemap.size();
    if (nodemap.size() == CACHE_SIZE) {
        nodemap.erase(tail->key);
        tail->next->prev = nullptr;
        newi = tail->i;
        tail = tail->next;
    }
    Node newnode { 
        key, newi, value, nullptr, head
    };
    nodemap.emplace(key, newi);
    nodes[newi] = newnode;
    if (head) {
        head->next = &nodes[newi];
    }
    if (!tail) {
        tail = &nodes[newi];
    }
    head = &nodes[newi];
}

pair<bool, int> isadj(int a, int b) {
    ll key = ((ll)a << 32) | b;
    auto it = nodemap.find(key);
    int gg;
    if (it == nodemap.end()) {
        gg = _gcd(a, b);
        add_node(key, gg);
    } else {
        Node* node = &nodes[it->second];
        front_node(node);
        gg = node->value;
    }
    bool out = issquare(a/gg) && issquare(b/gg);
    return {out, gg};
}

struct Group {
    int adjs;
    int comp;
    int next;
    int prev;
};

Group groups[N];

int main() {
    for (int i = 1; i <= 1000; ++i) {
        squares.insert(i*i);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    set<pair<ll, int> > queue;
    while(t--) {
        // # of adjs, gcd
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            Group g { 1, a, i + 1, i - 1 };
            groups[i] = g;
        }

        int q;
        cin >> q;

        for (int i = 0; i < q; ++i) {
            ll w;
            cin >> w;
            
            queue.insert({w, i});
        }

        ll current = -1;
        int maxadj = 0;
        bool converged = false;

        while (!queue.empty()) {
            auto w = queue.begin()->first;
            auto i = queue.begin()->second;
            queue.erase(queue.begin());
            if (!converged) {
                for (; current < w; ++current) {
                    bool changed = false;
                    for (int i = 0; i < n;) {
                        int nextgg = groups[i].comp;
                        for (int j = groups[i].next; j < n;) {
                            auto [adj, gg] = isadj(groups[i].comp, groups[j].comp);

                            if (adj) {
                                changed = true;
                                groups[i].adjs += groups[j].adjs;
                                auto next = groups[j].next;
                                auto prev = groups[j].prev;
                                groups[prev].next = next;
                                groups[next].prev = prev;
                                nextgg = min(nextgg, gg);
                            }
                            j = groups[j].next;
                        }
                        if (groups[i].adjs % 2 == 0) nextgg = 1;
                        groups[i].comp = nextgg;
                        maxadj = max(maxadj, groups[i].adjs);
                        i = groups[i].next;
                    }
                    if (!changed) {
                        converged = true;
                        break;
                    }
                }
            }
            output[i] = maxadj;
        }

        for (int i=0; i<q; ++i) {
            cout << output[i] << endl;
        }
    }
   return 0;
}


// lcm(x,y)*gcd(x,y) = x*y
// y = lcm*gcd/x
// y/gcd = lcm/x
// lcm(x,y)/gcd(x,y) = x*y / gcd(x,y)^2
// = p ^2
// x/gcd(x,y) =a
// y/gcd(x,y) =b
// x/gcd(x,y) = k^2
// 
// gcd(a,b) = 1
// a*b = p ^2
// p = sqrt(a) * sqrt(b)
// a = k^2
// b = z^2
// 
// p^2 * gcd(x,y)^2 = x*y
// (gcd(x,y)*p)^2 = x*y
// x*y should be perfect sqaure
// y*z / gcd(y,z)^2 = q^2
// x*z = (gcd(x,y)*p)^2*gcd(y,z)*q)^2 / y^2
// x^2*y*z*k*... = 
// y | (gcd(x,y)*p)^2
// x^2*y*z x*y x*z
// z - x - y
// x*y = gcd(x,y)*b * gcd(x,z)*d
// x^2*y*z 
// x*z = gcd(x,z)*a * gcd(x,z)*d
// y*z = gcd(x,y)*b * gcd(x,z)*c
// x - y adj y -z adj => x - z adj
// 
// x/gcd(x,y) = a^2
// z/gcd(t,z) != perfect sqaure
// 
// k^2,x,y,k,...
// R * z 
// gcd(z, x*y*k*..) | gcd(z,y)*gcd(z,y)*... 
// gcd(z, x*y*k*..) = n * gcd(z,y)*gcd(z,y)*... 
// z *x*y*k... / gcd(...) = z / gcd(z,y)
// z/gcd(y,z) != perfect square
// 
// x*
// d*c
// d*c = p^2
// x - y - z
// x y z will be all adj after thing
// x*z 
// b = perfect squrare
// a = perfect square 
// 
// 
// x*y*z = (gcd(x,y)*p)^2 * z
// x*y = perfect sqaure
// y*z = perfect sqaure
// if adjs = even, perfect sqaure
// odd, not sure
// x*y*z*d x*y*z*d 
// lcm(x,y)/((x*y)/lcm(x,y))
// lcm(x,y)^2/x*y = p^2
// lcm(x,y) = sqrt(p^2*x*y)
// = p * sqrt(x*y)
// 
// x/gcd(x,y) * y/gcd(x,y)
// lcm/x * lcm/y
// = 2lcm/
// 
// x = 1,2,2,5
// y = 1,3,3,5
// z = 1,3,3
// gcd=  1 * 5
// lcm/gcd = 1,2,2,3,3
// lcm/gcd = x*y with corresponding primes removed
// p^2*a * q^2*b * ...
// after transform, they will become same
// then they will be bigger again
// (2*a,2*b,0) (0, 2*a, 2*b)
// (2*a,2*b+2*a,2*b)
// 
// d
// a - b - c
// d
// a*b*c - a*b*c - a*b*c
// a*b*c*d - a*b*c*d - a*b*c*d - a*b*c*d
// a*b*c*d**4 - a*b*c*d**4 - a*b*c*d**4 - a*b*c*d**4
// adj same
// a - b adj , b - c does not mean a - adj
// a - b - c
// gcd(a,b), gcd(a,c)
// gcd(b,c)
//
// a,b  a,b,c  b,c
// a,b -c- a,b,c -a- b,c
//    -a*c-
// a,b^2,c  a,b
// comibination 
// perfect square element p, f
// (p odd or even, f even)
// merge =
// same*2 + (p odd or even, f even)
// 
// a, b, c
// a - b = (p odd)
// b - c = (f even)
// a - c = (f odd)
// 
// a * b = lcm(a,b) * gcd(a,b)
// b * c = lcm(b,c) * gcd(a,b)
// b = gcd(a,b) * gcd(b,c) + (p odd, f even)
// c = gcd(b,c) + (f odd)
// a = gcd(a,b) + (p odd)
// 
// gcd(b,c) f even
// 
// gcd(a,b) gcd(b,c)
// a^2,b^2,c d  a^2,b^2,c
// b,c
// 
// c -  - a
// a*c
// 

// a - b
// c - d
// ab=gcd(a,b)^2*b^2*a^2
// cd=gcd(c,d)^2*c^2*d^2
// ab = p ^2
// abc = p^2*gcd(a,c)
// gcd(a,c) * gcd(x,y) = perfect sqaure
//  gcd(a,c) * gcd(x,y) / gcd(gcd(a,c), gcd(x,y))
// 
// abcd = p^2
// 
// xy = p^2*gcd(x,y)
//
// gcd(a,c) * gcd(x,y) = p^2
// gcd(gcd(a,c), gcd(x,y)) = gcd(a,c,x,y)
//
// 
// gcd()
// gcd(a,c) g(x,y)
// 
