#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	int cse = 1;

	while (t--) {
		int n;
		cin >> n;

		bool pos = true;
		vector<char> res(n);
		vector<pair<pair<int, int>, int>> act(n);

		for (int i = 0; i < n; ++i) {
			int l, r;
			cin >> l >> r;
			act[i] = {{l, r}, i};
		}

		sort(act.begin(), act.end());
		int j = -1, c = -1;

		for (pair<pair<int, int>, int> d : act) {
			auto cur = d.first;
			if (cur.first >= j) {
				j = cur.second;
				res[d.second] = 'J';
			} else if (cur.first >= c) {
				c = cur.second;
				res[d.second] = 'C';
			} else {
				pos = false;
			}
		}

		string r = "";
		for (char x : res)
			r += x;

		if (!pos)
			r = "IMPOSSIBLE";
		printf("Case #%d: ", cse++);
		fflush(stdout);
		cout << r << endl;
	}

	return 0;
}

