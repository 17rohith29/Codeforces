#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> d(n + 1);
	vector<pair<int, int>> edges;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		d[i] = {x, i};
	}

	sort(d.begin(), d.end());
	int zeroes = 0;
	for (auto x : d)
		if (x.first == 0) zeroes++;
	bool pos = true;

	if (zeroes < 0 || d[1].first != 0)
		pos = false;

	if (pos) {
		deque<pair<int, int>> can_use;
		pair<int, int> cur = d[1];
		int count = 0;
		for (int i = 2; i < d.size(); i++) {
			if (cur.second == -1) {
				pos = false;
				break;
			}
			// add next edge
			pair<int, int> now = d[i];
			if (now.first - cur.first == 1) {
				edges.push_back({cur.second, now.second});
				can_use.push_back(now);
				count++;
			} else if (now.first - cur.first <= 0) { // not possible
				pos = false;
				break;
			} else {
				cerr << "here?";
				while (!can_use.empty()) {
					cur = can_use.front();
					can_use.pop_front();

					if (now.first - cur.first == 1)
						break;
				}

				if (now.first - cur.first != 1 || 2 > k) {
					pos = false;
					break;
				} else {
					count = 2;
					edges.push_back({cur.second, now.second});
					can_use.push_back(now);
				}
			}

			// all k used up?
			if (count >= k) {
				if (can_use.size() > 0 && 1 < k) {
					cur = can_use.front();
					can_use.pop_front();
					count = 1;
				} else {
					cur = {-1, -1};
				}
			}
		}
	}

	if (!pos) cout << -1;
	else {
		cout << edges.size() << endl;

		for (auto x : edges) {
			cout << x.first << " " << x.second << endl;
		}
	}


	return 0;
}

