#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	while (q--) {
		string g;
		cin >> g;

		int store[4] = {0, 0, 0, 0};
		for (char ch : g) {
			switch(ch) {
				case 'L': store[0]++;break;
				case 'U': store[1]++;break;
				case 'R': store[2]++;break;
				case 'D': store[3]++;break;
			}
		}

		int u = min(store[1], store[3]);
		int l = min(store[0], store[2]);

		if (u == 0)
			l = min(l, 1);
		else if (l == 0)
			u = min(u, 1);

		cout << 2 * (u + l) << endl;
		string s = "";
		for(int i = 0; i < l; i++)
			s.push_back('L');
		for(int i = 0; i < u; i++)
			s.push_back('U');
		for(int i = 0; i < l; i++)
			s.push_back('R');
		for(int i = 0; i < u; i++)
			s.push_back('D');

		cout << s;
		if (q)
			cout << endl;
	}

	return 0;
}

