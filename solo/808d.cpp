#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

bool solve(ll *a) {
	ll sum = 0;
	for (ll i = 0; i < n; ++i) {
		ll x = a[i];
		sum += x;
	}

	if (sum % 2 != 0) return false;

	sum = sum / 2;
	unordered_set<ll> st;
	ll cur_sum = 0;
	for (ll i = 0; i < n; ++i) {
		ll x = a[i];
		cur_sum += x;
		st.insert(x);

		ll comp = cur_sum - sum;
		if (st.find(comp) != st.end())
			return true;
	}

	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	ll a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	bool res = solve(a);
	if (!res) {
		reverse(a, a + n);
		res = solve(a);
	}

	if (res)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}

