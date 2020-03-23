#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;
int n, m;
long long fact(int x) {
	long long res = 1;
	for (int i = 2; i <= x; i++) {
		res = res * i % MOD;
	}

	return res;
}

long long gcd(long long a, long long b, long long &x, long long &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd(b % a, a, x1, y1);
	x =( y1 - (b / a) * x1);
	y = x1;
	return d;

}

long long choose(int a, int b) {
	long long x = fact(a) % MOD;
	long long y = fact(b);
	y = y * fact(a - b) % MOD;
	long long p, q;
	gcd(MOD, y,  p, q);
	while (q < 0)
		q += MOD;

	return x * q % MOD;
}

long long pow(int n) {
	if (n == 0) return 1LL;
	else if (n <= 30) {
		long long res = 1;
		res = res << n;
		res %= MOD;
		return res;
	} else {
		long long res = 1;
		res = res << 30;
		res = res % MOD;
		return res * pow(n - 30) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	long long res = choose(m, n - 1);
	res = res * (n - 2) % MOD;
	long long two = pow(n - 3);
	res = res * two % MOD;

	cout << res;

	return 0;
}

