#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll inf = -pow(10, 10);
ll ans = inf;
vector<vector<int>> graph(300000 + 5);
ll w[300000 + 5];
ll dp[300000 + 5];
int cnt = 0;

ll dfs(int n, int p, bool second) {
	ll res = w[n];

	if (dp[n] != inf)
		res = dp[n];
	else {
		for (int v : graph[n]) {
			if (v != p) {
				res += max(0LL, dfs(v, n, second));
			}
		}
	}

	dp[n] = res;

	if (!second)
		ans = max(ans, res);

	if (second && res == ans) {
		dp[n] = 0; // makes it unusable
		res = 0;
		cnt++;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i < n + 1; ++i) {
		cin >> w[i];
		dp[i] = ans;
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 0, false);
	for (int i = 1; i < n + 1; ++i) dp[i] = inf;
	dfs(1, 0, true);

	cout << ans * cnt << " " << cnt;

	return 0;
}

