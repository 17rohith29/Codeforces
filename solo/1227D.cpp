#include <bits/stdc++.h>
using namespace std;

struct seg_tree {
	int n;
	int mx;
	vector<int> segment;

	seg_tree(int N) {
		n = N;
		mx = 4 * n + 10;
		segment.resize(mx);
		for (int i = 0; i < 4 * n + 10; i++)
			segment[i] = 0;
	}

	void add(int index) {
		add(index, n - 1);
	}

	void add(int index, int end_arr, int vertex = 1, int b_arr = 0) {
		if (b_arr == end_arr && end_arr == index) {
			segment[vertex]++;
		} else if (end_arr < index || b_arr > index)
			return;
		else {
			int mid = (end_arr + b_arr) / 2;
			add(index, mid, 2 * vertex, b_arr);
			add(index, end_arr, 1 + 2 * vertex, mid + 1);

			segment[vertex]++;
		}
	}

	int find(int k) {
		return find(k, n -1);
	}
	// finds the kth index
	int find(int k, int end_arr, int vertex = 1, int b_arr = 0) {
		if (b_arr == end_arr) {
			return b_arr;
		} else {
			int mid = (end_arr + b_arr) / 2;

			if (segment[2 * vertex] >= k)
				return find(k, mid, 2 * vertex, b_arr);
			else {
				return find(k - segment[2 * vertex], end_arr, 2 * vertex + 1, mid + 1);
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	long long a[n];
	vector<pair<long long, int>> store(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		store[i] = {a[i], i};
	}

	sort(store.begin(), store.end(), [](pair<long long, int> a, pair<long long, int> b) {
			if (a.first != b.first) return a.first > b.first;
			else return a.second < b.second;
			});

	int m;
	cin >> m;

//	cerr << "printing out store " << endl;
//	for (auto x : store ) {
//		cout << x.first << " " << x.second << endl;
//	}

	vector<pair<pair<int, int>, int>> queries(m);
	vector<long long> res(m);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		queries[i] = {{a, b}, i};
	}

	sort(queries.begin(), queries.end());
	seg_tree tree(n);

	int q_start = 0;

	for (int i = 0; i < n; i++) {
		tree.add(store[i].second); // adding the index

		while (q_start < m && queries[q_start].first.first == 1 + i) {
			int index_no = queries[q_start].second;
			int kth = tree.find(queries[q_start].first.second);
			res[index_no] = a[kth];
			q_start++;
		}
	}

	for (int i = 0; i < m; i++) {
		if (i != 0) cout << endl;
		cout << res[i];
	}

	return 0;
}
