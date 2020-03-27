#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int check[3000][3000];

long long solve(int a, int c) {
	long long b = 0;

	for (int x : graph[a]) {
		if (check[x][c]) {
			b++;
		}
	}

	return b * (b - 1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(check, 0, sizeof(check));

	int n, m;
	cin >> n >> m;

	graph.resize(n);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		graph[a - 1].push_back(b - 1);
		check[a - 1][b - 1] = 1;
	}

	long long res = 0;

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			res += solve(i, j);
			res += solve(j, i);
		}

	cout << res;

	return 0;
}

