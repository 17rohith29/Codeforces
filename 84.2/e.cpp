#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

vector<long long> f_s;
vector<long long> p;

void prec(int n) {
	f_s.push_back(0);
	f_s.push_back(1);
	p.push_back(1);

	for (int i = 2; i < n + 5; i++) {
		f_s.push_back(f_s.back() * i % MOD);
		p.push_back(p.back() * 10 % MOD);
	}
}


long long fact(int x) {
	return f_s[x];
}

long power(int x) {
	return p[x];
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

typedef long long ll;
long long solve(int n, int x){
	int  rem = n - x;

	if (rem == 0) return 10;
	else {

		ll twice = 10 * 2; // first and last permutation
		twice = twice * 9 % MOD; // we choose 1 number. rest can be any nums
		twice = twice * power(rem - 1) % MOD;

		ll other = 10 * (rem - 1) % MOD; // we can choose every block not first or last. (n - x + 1) - 2 [removes first and last] = n - x - 1 = rem - x
		other = other * 9 * 9 % MOD;
		other = other * power(rem - 2) % MOD;

		return (other + twice )% MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	prec(n);

	for (int i = 0; i < n; i++) {
		if (i != 0)
			cout << " ";
		cout << solve(n, i+1);
	}
	return 0;
}

