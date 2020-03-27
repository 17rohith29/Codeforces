#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	ll I;
	cin >> n >> I;

	ll k = 8 * I / n;
	ll K = 1LL << min(20LL, k); // max size we can have
	map<ll, pair<ll, ll>> store;
	vector<ll> a, b(n);

	ll prev = -1, cur;

	for (ll i =0; i < n; ++i)
		cin>>b[i];

	sort(b.begin(), b.end());

	for (ll i = 0; i < n; ++i) {
		cur=b[i];

		if (prev == cur) {
			auto f = store[prev];
			f.second++;
			store[prev] = f;
		} else {
			store[cur] = {i, i};
			a.push_back(cur);
		}

		prev = cur;
	}

	ll res = n;
	for (int i = 0; i < a.size(); i++) {
		ll last = min((ll)a.size() - 1, i + K - 1);
		ll included = store[a[last]].second + 1 - store[a[i]].first;
		ll excluded = n - included;
		res = min(res, excluded);

		//cout << " for element " << a[i] << " The last Element is " << a[last] <<endl;
	}

	cout << res;

	return 0;
}

