#include <bits/stdc++.h>
using namespace std;

void fill(int *b, string x) {
	for (int i = 0; i < 26; i++)
		b[i] = 0;
	for (char a : x) {
		b[a - 'a']++;
	}
}

int parity(string x) {
	int res = 0;
	for (int i = 0; i < x.length(); i++)
		for (int j = i + 1; j < x.length(); j++) {
			if (x[j] < x[i])
				res++;
		}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	while (q--) {
		int len;
		string x, y;
		cin >> len >> x >> y;

		int ba[26], bb[26];
		fill(ba, x);
		fill(bb, y);

		bool dbl = false, eql = true;
		for (int i = 0; i < 26; i++) {
			if (ba[i] != bb[i]) {
				eql = false;
				break;
			} else if (!dbl) {
				dbl = (ba[i] > 1);
			}
		}

		if (!eql) {
			cout << "NO";
		} else if (dbl) {
			cout << "YES";
		} else {
			if (parity(x) % 2 == parity(y) % 2)
				cout << "YES";
			else
				cout << "NO";
		}

		if (q) cout << endl;
	}

	return 0;
}

