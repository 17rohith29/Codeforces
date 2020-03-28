#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;

	long long red[a], green[b], cless[c];
	for (int i = 0; i < a; ++i)
		cin >> red[i];
	for (int i = 0; i < b; ++i)
		cin >> green[i];
	for (int i = 0; i < c; ++i)
		cin >> cless[i];

	sort(red, a + red);
	sort(green, green + b);
	sort(cless, cless + c);

	vector<long long> res;
	for (int i = 0; i < x; i++)
		res.push_back(red[a - 1 - i]);
	for (int i = 0; i < y; i++)
		res.push_back(green[b - 1 - i]);

	sort(res.begin(), res.end());
	int j = 0;
	for (int i = c - 1; i >= 0; i--) {
		if (j >= res.size()) break;
		if (cless[i] > res[j]) {
			res[j] = cless[i];
			j++;
		}
	}

	long long ans = 0;
	for (long long x : res)
		ans += x;

	cout << ans;

	return 0;
}

