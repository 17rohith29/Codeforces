#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<vector<long long>> graph(n + 1);
	vector<pair<long long, long long>> edges(n);
	vector<long long> res(n);

	int mx = 0;
	int val = -1;

	for (long long i = 1; i < n; i++) {
		long long u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);

		edges[i] = {u, v};

		if (mx < graph[u].size()) {
			mx = graph[u].size();
			val = u;
		}
		if (mx < graph[v].size()) {
			mx = graph[v].size();
			val = v;
		}
	}

	long long ans = n - 2;
	int b = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (mx < 3)
			res[i] = ans--;
		else {
			if (edges[i].first == val || edges[i].second == val)
				res[i] = b++;
			else
				res[i] = ans--;
		}
	}

	for (long long i = 1; i < n;  i++){
		if (i != 1) cout << endl;
		cout << res[i];
	}


	return 0;
}

