#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define For(i,s,n) for(int i =(s); i < (n); ++i)
#define ll long long
#define N 200
using namespace std;

int n;
int f[N];
bool graph[N][N];

bool onstack[N];
int indice[N];
int lowlink[N];
int index;
stack<int> s;
vector< vector<int> > cycles;

void strongconnect(int v) {
	index++;
	indice[v] = index;
	lowlink[v] = index;
	s.push(v);
	onstack[v] = true;

	For(i, 0, n) {
		if(!graph[v][i]) continue;
		if(indice[i] == -1) {
			cout << "i:" << f[v] << " " << f[i] << endl;
			strongconnect(i);
			lowlink[v] = min(lowlink[v], lowlink[i]);
		} else if(onstack[i]) {
			lowlink[v] = min(lowlink[v], indice[i]);
		}
	}

	if(lowlink[v] == indice[v]) {
		vector<int> out;
		if (s.size() < 3) return;
		while(!s.empty()) {
			int w = s.top();
			s.pop();
			onstack[w] = false;
			out.push_back(w);
		}
		cycles.push_back(out);
	}
}

bool isPrime(int n) {
	if(n <= 1) return false;
	if(n%2 == 0) return (n == 2);

	for(int i = 3; i*i <= n; i+=2)
		if (n % i == 0)
			return false;

	return true;
}

int main() {
	cin >> n;
	For(i, 0, n) cin >> f[i];
	For(i, 0, n)
		For(j, i+1, n)
			graph[i][j] = graph[j][i] = isPrime(f[i]+f[j]);

	For(i, 0, n) {
		For(j, 0, n)
			cout << graph[i][j] << ", ";
		cout << endl;
	}

	fill_n(indice, n, -1);
	For(i, 0, n)
		if(indice[i] == -1)
			strongconnect(i);

	if(!s.empty()) {
		cout << "Impossible" << endl;
		return 0;
	}

	cout << cycles.size() << endl;
	for(auto c: cycles) {
		cout << c.size() << " ";
		for(auto i: c) {
			cout << f[i] <<" ";
		}
		cout << endl;
	}
	return 0;
}
