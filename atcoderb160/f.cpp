#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
long long mod = 1e9 + 7;
vector<long long> dp;
vector<long long> fact(200000 + 10);
vector<long long> nodes_below;
vector<long long> result;

long long gcd(long long a, long long b, long long &x, long long &y) {
	// finds gcd (a, b) with b being the larger number
	long long q, r;
	q = b / a; r = b % a;

	if (r == 0) { // gcd is a
		x = 1;
		y = 0;
		return a;
	} else {
		long long x1, x2, ans;
		ans = gcd(r, a, x1, x2);
		x = x2 - q * x1;
		y = x1;

		return ans;
	}
}

long long inverse(long long a) {
	long long x, y;
	gcd(a, mod, x, y);
	return x;
}


long long dfs(int cur, int parent) {
	long long n = 1;
	long long denom = 1;
	long long numerator = 1;

	for (int x : graph[cur]) {
		if (x != parent) {
			long long y = dfs(x, cur);
			denom = denom * (fact[y]) % mod;
			numerator = numerator * dp[x] % mod;
			n += y;
		}
	}

	long long x, y;
	gcd(denom, mod, x, y);
	while (x < 0)
		x += mod;
	x = x % mod;
	numerator = numerator * fact[n - 1];
	dp[cur] = numerator * x % mod;

	nodes_below[cur] = n;
	return n;
}

void reroot(int node, int parent = -1) {
	long long old = nodes_below[parent], old_c = nodes_below[node];
	long long dold = dp[parent], dold_c = dp[node];

	if (parent != -1) {
		// change
		nodes_below[node] = old;
		nodes_below[parent] = old - old_c;

		// change dp part
		dp[parent] = dold * inverse(dold_c) % mod;
		// change fact
		dp[parent] = dp[parent] * fact[nodes_below[parent] - 1] %mod;
		dp[parent] = dp[parent] * inverse(fact[old - 1]) % mod;
		// change denom
		dp[parent] = dp[parent] * fact[old_c] % mod;

		while (dp[parent] < 0)
			dp[parent] += mod;

		dp[node] = dp[node] % mod;

		// change fact
		dp[node] = dold_c * fact[nodes_below[node] - 1] % mod;
		dp[node] = dp[node] * inverse(fact[old_c - 1]) % mod;
		// denom 1
		dp[node] = dp[node] * inverse(fact[nodes_below[parent]]) % mod;
		// num 1
		dp[node] = dp[node] * dp[parent] % mod;
		// now update

		while (dp[node] < 0)
			dp[node] += mod;

		dp[parent] = dp[parent] % mod;
		result[node] = dp[node];
	}

	// recursive call to propagate reroot
	for (int x : graph[node]) {
		if (x != parent)
			reroot(x, node);
	}

	// remove changes
	if (parent != -1) {
		nodes_below[node] = old_c;
		nodes_below[parent] = old;
		dp[node] = dold_c;
		dp[parent] = dold;
	}
}

void fill() {
	fact[0] = 1LL;
	for (long long i = 1; i < 200000 + 5; i++) {
		fact[i] = i * fact[i - 1] % mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fill();

	int n;
	cin >> n;

	graph.resize(n);
	dp.resize(n);
	nodes_below.resize(n);
	result.resize(n);

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;

		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	fill(dp.begin(), dp.end(), 0);
	dfs(0, -1);
	result[0] = dp[0];
	reroot(0);

	for (int i = 0; i < n; ++i) {
		while (result[i] < 0)
			result[i] += mod;
		cout << result[i] << endl;
	}

	return 0;
}

