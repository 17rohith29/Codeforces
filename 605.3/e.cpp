#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int a[n];
	int res[n];
	int seen[n];

	for (int i= 0; i < n; ++i) {
		cin >> a[i];
		res[i] = n + 1;
		seen[i] = 0;
	}

	vector<vector<int>> come_from(n);
	for(int i = 0; i < n; ++i) {
		int np = a[i] + i;
		int N = i - a[i];

		if (np < n && np >= 0)
			come_from[np].push_back(i);
		if (N < n && N >= 0)
			come_from[N].push_back(i);
	}

	list<int> next;
	int val = 2;

	for (int j = 0; j < n; ++j) {
		int part = a[j] % 2;
		int np = a[j] + j;
		int Np = j - a[j];

		if (np < n && np >= 0 && a[np] % 2 != part) {
			res[j] = 1;
		}
		if (Np < n && Np >= 0 && a[Np] % 2 != part) {
			res[j] = 1;
		}
		if (res[j] == 1) {
			seen[j] = 1;
		for (int x : come_from[j])
			if (seen[x] == 0) {
				next.push_back(x);
		}}
	}

	while (!next.empty()) {
		cerr << endl;
		list<int> after;
		for (int x: next) {
			if (seen[x] == 1) continue;
			res[x] = min(res[x], val);
			seen[x] = 1;

			for (int j : come_from[x])
				if (seen[j] == 0)
					after.push_back(j);
		}
		val++;
		next = after;
	}

	for (int i = 0; i < n; ++i) {
		if (i != 0) cout << " ";
		if (res[i] == n + 1) cout << -1; else
		cout << res[i];
	}

	return 0;
}

