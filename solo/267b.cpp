#include <bits/stdc++.h>
using namespace std;

struct comp {
	size_t operator() (const pair<int, int> &p) const {
		return hash<int>{}(p.first) ^ hash<int>{}(p.second);
	}
};

int n, a, b;
unordered_map<int, unordered_set<int>> dominoes;
unordered_map<pair<int, int>, int, comp> indes;
vector<pair<int, int>> result;
vector<string> output;
bool done = false;

solve(int start) {
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	result.resize(n + 1);

	for (int i = 0; i < n; ++i) {
		cin >> a >> b;

		if (dominoes.find(a) == dominoes.end()) {
			unordered_set<int> x;
			x.insert(b);
			dominoes[a] = x;
		} else
			dominoes[a].insert(b);
	}

	for (auto it = dominoes.begin(); it != dominoes.end(); it++) {
		solve(it->first);
		if (done == true) {
			break;
		}
	}

	if (done) {
		int i = 1;

		for (auto x : result) {
			int idx;
			string out = "+";
			if (dominoes[x.first].find(x.second) != dominoes[x.first].end()) {
				idx = indes[x];
			} else {
				idx = indes[{x.second, x.first}];
				out = "-";
			}

			output[idx] = to_string(i++) + out;
		}

		for (int j = 1; j <= n; ++j)
			cout << output[j];
	} else {
		cout << "No solution";
	}


	return 0;
}

