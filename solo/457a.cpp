#include <bits/stdc++.h>
using namespace std;

string x, y;

vector<char> fix(string x) {
//	cerr << "x = " << x << endl;
	vector<char> res;

	vector<int> b(100010);

	for (int i = 0; i < x.size(); i++)
		b[b.size() - 1 - i] = x[x.size() - 1 - i] - '0';

	for (int i = 4; i < b.size(); i++) {
		if (b[i] > 0 && b[i - 1] > 0) {
			b[i] = 0;
			b[i - 1] = 0;
			b[i - 2] = 1;

			if (b[i - 2] == b[i - 3]) {
				i = i - 3;
			}
		}
	}

	bool seen = false;
	for (int i = 0; i < b.size(); i++)
		if (seen || b[i] > 0) {
			seen = true;
			int c = b[i];
			res.push_back('0' + min(c, 1));
			c--;
			if (c > 0) {
				b[i + 1] += c;
				b[i + 2] += c;
			}

		}

//	for (char x : res) cerr << x << " ";
//	cerr << endl;

	return res;
}

string les() {
	auto a = fix(x), b = fix(y);

	if (a.size() < b.size())
		return "<";
	else if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++)
			if (a[i] != b[i]) {
				if (a[i] == '1')
					return ">";
				else return "<";
			}

		return "=";
	}
	else return ">";
}

// 100 = 011 = 01011

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;

	cout << les();

	return 0;
}

