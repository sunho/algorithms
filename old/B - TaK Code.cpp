#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<string> A(n, string(m, ' '));
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin >> A[i][j];
		}
	}
	vector<string> pat1 = {"###.","###.","###.","...."};
	vector<string> pat2 = {"....",".###",".###",".###"};
	vector<pair<int,int>> ans;
	for (int i=0;i<n-8;i++){
		for (int j=0;j<m-8;j++){
			vector<string> top;
			for (int x=i;x<i+4;x++){
				top.push_back(A[x].substr(j,4));
			}
			vector<string> bot;
			for (int x=i+5;x<i+9;x++){
				bot.push_back(A[x].substr(j+5,4));
			}
			if (pat1 == top && pat2 == bot) {
				ans.push_back({i,j});
			}
		}
	}
	for (auto [x,y] : ans) {
		cout << x+1 << " " << y + 1 << "\n";
	}
}
