#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, x, y;
	cin >> n >> x >> y;

	// first calculate distance as though it has been normal
	long long dist[n + 1][n + 1];
	long long INF = 1e4;
	memset(dist, INF, sizeof(dist));

	for (long long i = 1; i <= n; ++i) {
		for (long long j = 1; j <= n; ++j) {
			dist[i][j] = abs(j - i);
		}
	}

	for (long long i = 1; i <= n; ++i) {
		for (long long j = 1; j <= n; ++j) {
			dist[i][j] = min(dist[i][j], dist[i][x] + 1 + dist[y][j]);}
	}

	long long res[n];
	memset(res, 0, sizeof(res));

	for (long long i = 1; i <= n; ++i)
		for (long long j = 1 + i; j <= n; ++j) {
			if (dist[i][j] < n && dist[i][j] >= 0)
				res[dist[i][j]]++;
		}

	for (long long i = 1; i < n; ++i)
		cout << res[i]<< endl;

	return 0;
}

