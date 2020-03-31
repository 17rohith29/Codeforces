#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

int solve() {
	vector<deque<int>> store;
	store.resize(n + 1);
	int money = 0;

	auto cmp = [&] (int a, int b) {
		if (store[a].size() == 0) return true;
		if (store[b].size() == 0) return false;
		return store[a].front() > store[b].front();
	};

	set<int, decltype(cmp)> lib(cmp);

	for (int i = 0; i < a.size(); ++i) {
		int elt = a[i];
		store[elt].push_back(i);
	}

	for (int elt : a) {
		if (lib.find(elt) == lib.end()) {
			money++;

			while (lib.size() >= k) {
				lib.erase(lib.begin());
			}

			store[elt].pop_front();
			lib.insert(elt);
		} else {
			lib.erase(elt);
			store[elt].pop_front();
			lib.insert(elt);
		}
	}

	return money;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	a.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cout << solve();

	return 0;
}

