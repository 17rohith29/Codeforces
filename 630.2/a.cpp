#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long a, b, c, d;
long long x, y, X, XX, Y, YY;

bool solve(long long x, long long y) {
	if (x <= XX  && x >= X) {
		if ((y <= YY && y >= Y)) {
			return true;
		} else {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);

	long long t;
	cin >> t;

	while (t--) {
		cin >> a >> b >> c >> d;
		cin >> x >> y >> X >> Y >> XX >> YY;
		ll n_x = x + b - a;
		ll n_y = y + d - c;

		bool s = false;
		if ((solve(x, y)) && solve(n_x,n_y)) {
			if (n_x == x && (a > 0 || b > 0)) {
				s = solve(x + 1, y) || solve (x - 1, y);
			} else s = true;

			if (s) {
				if (n_y == y && (c > 0 || d > 0))
					s = solve(x, y + 1) || solve (x, y - 1);
			}
		}

		if (s)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}

	return 0;
}

