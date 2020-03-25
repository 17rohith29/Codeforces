#include <bits/stdc++.h>
using namespace std;

vector<int> p, c;

int solve() {
	int ans = 2e5 + 10;
	int used[c.size()];
	memset(used, 0, sizeof(used));

	// let us first pick all cycles
	for (int i = 0; i < p.size(); i++) {
		if (used[i] == 1)
			continue;

		vector<int> cycle;

		// getting cycle
		int index = i;
		while (used[index] == 0) {
			cycle.push_back(index);
			used[index] = 1;
			index = p[index];
		}

		for (int cycle_length = 1; cycle_length <= cycle.size(); cycle_length++) {
			// the cycle length should be gcd(the power raised to - k, cycle length) -> cycle length | m
			if (cycle.size() % cycle_length != 0)
				continue;
			else {
				// we will now check all cycles of length cyclelength to see if it works
				for (int start = 0; start < cycle_length; start++) {
					bool works = true;

					for (int j = start; j + cycle_length < cycle.size(); j += cycle_length)
						if (c[cycle[j]] != c[cycle[j + cycle_length]])
							works = false;

					if (works) {
						ans = min(ans, cycle_length);
						break;
					}
				}
			}
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;

		p.resize(n);
		c.resize(n);

		for (int i = 0; i < n; i++) {
			cin >> p[i];
			p[i]--;
		}

		for (int i = 0; i < n; i++)
			cin >> c[i];

		cout << solve();

		if (t)
			cout << endl;
	}

	return 0;
}

