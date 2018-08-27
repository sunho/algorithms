#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > graph;

void update(int a, int b, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = min(graph[i][a] + graph[a][b] + graph[b][j], graph[i][j]);
		}
	}
}

long long sum(int n) {
	long long out = 0;
	for (int i =0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			out += graph[i][j];
		}
	}
	return out;
}

int main() {
	int n;
	cin >> n;
	graph = vector< vector<int> >(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	int k;
	cin >> k;

	long long s = 0;
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a --;
		b --;
		if (graph[a][b] <= c) {
			if (i == 0) {
				s = sum(n);
			}
			cout << s << ' ';
		} else {
			graph[a][b] = c;
			graph[b][a] = c;
			update(a, b, n);
			update(b, a, n);
			s = sum(n);
			cout << s << ' ';
		}
	}
	return 0;
}
