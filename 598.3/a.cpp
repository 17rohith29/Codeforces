#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	while(q--) {
		ll a, b, n, s;
		cin >> a >> b >> n >> s;
		bool res = false;
		ll x = s / n;

		ll rem  = s - min(x, a) * n;
		res = (b >= rem);

		if (res) cout << "YES"; else cout << "NO";
		if (q) cout << endl;
	}

	return 0;
}

