#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	pair<ll, int> div[n + 1];
	pair<ll, int> a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
		div[i + 1].first = INF;
		div[i + 1].second = -1;
	}

	sort(a, a + n);
	div[0].first = 0;
	div[0].second = -1;

	for (int i = 0; i <= n; i++) {
		for (int j = 3; j <= 5 && i + j <= n; j++) {
			if (div[i].first == INF) continue;
			// i th team is done. next team is i + j
			// with members a[i] a[i + 1] ... a[i + j - 1]
			if (div[i + j].first > div[i].first + a[i + j - 1].first - a[i].first) {
				div[i + j].first = div[i].first + a[i + j - 1].first - a[i].first;
				div[i + j].second = i;
			}
		}
	}

	int res[n]; // array that stores which place each goes
	int i = n;
	int grp = 0;


	while (i != -1) {
		int prev = div[i].second;
		if (prev == -1) break;
		grp++;
		for (int j = prev + 1; j <= i; j++) {
			int member = j - 1;
			res[a[member].second] = grp;
		}

		// updates
		i = prev;
	}

	cout << div[n].first << " " << grp << endl;

	for (int i = 0; i < n; i++) {
		if (i != 0)
			cout << " ";
		cout << res[i];
	}


	return 0;
}

