#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<long long> a;
ll n;

pair<int, int> next(int i, int j) {
	int next_j, next_i; ll next = i;

	if (j == 0){
		next_j = 1;
		next += a[i];
	} else {
		next_j = 0;
		next -= a[i];
	}

	if (next >= n || next < 0)
			next_i = -1;
		else
			next_i = next;

	return {next_i, next_j};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	a.resize(n);

	for (int i = 1; i < n; ++i)
		cin >> a[i];

	ll dp[n][2];
	vector<pair<int, int>> back[n][2];
	memset(dp, -1, sizeof(dp)); // 1 means it does not terminate
	vector<pair<int, int>> process;

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 2; j++) {
			auto nxt = next(i, j);

			if (nxt.first != -1) {
				back[nxt.first][nxt.second].push_back({i, j});
			} else {
				process.push_back({i, j});
			}
		}
	}

	// lets now fill dp
	while (!process.empty()) {
		vector<pair<int, int>> after;

		while (!process.empty()) {
			auto cur = process.back();
			process.pop_back();

			if (dp[cur.first][cur.second] != -1)
				continue;

			// update dp
			ll add = a[cur.first];
			auto nxt = next(cur.first, cur.second);

			if (nxt.first == 0) {
				add = -1;
			} else if (nxt.first != -1) {
				if (dp[nxt.first][nxt.second] == -1) {
					add = -1;
				} else
				add += dp[nxt.first][nxt.second];
			}

			// add to process list
			dp[cur.first][cur.second] = add;
			if (add != -1)
			for (auto x : back[cur.first][cur.second]) {
				if (dp[x.first][x.second] == -1) { // not processed
					after.push_back(x);
				}
			}
		}

		process = after;
	}

	for (int i = 1; i < n; i++) {
		// from 1 -> 1 in dp array. from 2 -> 2 in dp array ..
		long long y = i;
		if (dp[i][1] == -1)
			y = -1;
		else y += dp[i][1];

		cout << y << endl;
	}

	return 0;
}

